/** @file Darwin.c++
 *  @brief The main file containing the Species, Creature and Darwin classes
 */


// --------
// includes
// --------

#include <cassert> // assert
#include <string>  //
#include <cstdlib> // rand, srand
#include <iostream>  //cout
#include <cstdlib>   // vector
#include <vector>   // vector
#include <sstream> //istringstream

#include "Life.h"

using namespace std;

// -------------
// AbstractCell Methods
// -------------

void AbstractCell::toNewValue(){
	value = newValue;
	newValue = 0;
}

ostream& operator << (ostream& o, AbstractCell* cell){
	return o << cell->value;
}

// -------------
// ConwayCell Methods
// -------------

void ConwayCell::update(vector<AbstractCell*> neighbors){
	int aliveNeighbors = 0;
	for(AbstractCell* cellPtr: neighbors){
		if(cellPtr != 0){
			if(cellPtr->isAlive()){
				aliveNeighbors++;
			}
		}
	}
	if(aliveNeighbors == 3){
		newValue = '*';
	}
	else if(aliveNeighbors == 2){
		if(isAlive()){
			newValue = '*';
		}
		else{
			newValue =  '.';
		}
	}else{
		newValue =  '.';
	}
}

int ConwayCell::isAlive(){
	return value!='.';
}

int ConwayCell::isNewAlive() const{
	return newValue!='.';
}

AbstractCell* ConwayCell::clone() const{
	return new ConwayCell(value);
}

// -------------
// FredkinCell Methods
// -------------

void FredkinCell::update(vector<AbstractCell*> neighbors){
	int aliveNeighbors = 0;
	int pos = 0;
	for(AbstractCell* cellPtr: neighbors){
		if(pos==1 || pos==3 || pos==4 || pos==6){
			if(cellPtr != 0){
				if(cellPtr->isAlive()){
					aliveNeighbors++;
				}
			}
		}
		pos++;
	}
	if(value == '-'){
		if(aliveNeighbors == 1 || aliveNeighbors == 3){
			newValue = age + '0';
		}
		else{
			newValue = '-';
		}
	}
	else{
		if(aliveNeighbors == 0 || aliveNeighbors == 2 || aliveNeighbors == 4){
			newValue = '-';
		}
		else{
			age++;
			if(age>=9){
				newValue = '+';
			}
			else{
				newValue = age + '0';
			}
		}
	}
}

int FredkinCell::isAlive(){
	if(value!='-'){
		return age+1;
	}
	return 0;
}

int FredkinCell::isNewAlive() const{
	if(newValue!='-'){
		return age+1;
	}
	return 0;
}

AbstractCell* FredkinCell::clone() const{
	FredkinCell* f = new FredkinCell(value);
	f->age = age;
	return f;
}

// -------------
// Cell Methods
// -------------

void Cell::update(vector<AbstractCell*> neighbors){
	cell->update(neighbors);
	if (const FredkinCell* const p = dynamic_cast<const FredkinCell*>(cell)){
		if(p->isNewAlive()-1>1){
			delete cell;
			cell = new ConwayCell('*');
			newValue = '*';
		}
		else{
			if(p->isNewAlive()==0){
				newValue = '-';
			}else{
				newValue = p->isNewAlive()-1+'0';
			}
		}
	}else{
		if(cell->isNewAlive()==0){
			newValue = '.';
		}else{
			newValue = '*';
		}
	}
}

int Cell::isAlive(){
	return cell->isAlive();
}

int Cell::isNewAlive() const{
	return cell->isNewAlive();
}

AbstractCell* Cell::clone() const{
	return new Cell(value);
}

void Cell::toNewValue(){
	value = newValue;
	cell->toNewValue();
}