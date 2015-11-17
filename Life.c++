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

ostream& operator << (ostream& o, AbstractCell* cell){
	return o << cell->value;
}

void AbstractCell::toNewValue(){
	value = newValue;
	newValue = 0;
}

bool AbstractCell::isEqual(const AbstractCell& rhs){
	if(this->value == '.'){
		return rhs.value == '.';
	}
	else{
		return rhs.value != '.';
	}
}
// -------------
// ConwayCell Methods
// -------------

void ConwayCell::update(vector<AbstractCell*> neighbors, int row, int col, int width, int height){
	int aliveNeighbors = 0;
	for(AbstractCell* cellPtr: neighbors){
		if(cellPtr != 0){
			//if dead and not equal neighbor
			if(this-> value == '.' && !this->isEqual(*cellPtr)){
				aliveNeighbors++;
			}
			//if alive and equal neighbor
			else if(this-> value == '*' && this->isEqual(*cellPtr)){
				aliveNeighbors++;
			}
		}
	}
	if(aliveNeighbors == 3){
		newValue = '*';
	}
	else{
		newValue =  '.';
	}
}

// -------------
// FredkinCell Methods
// -------------

void FredkinCell::update(vector<AbstractCell*> neighbors, int row, int col, int width, int height){
	int aliveNeighbors = 0;
	for(AbstractCell* cellPtr: neighbors){
		if(cellPtr != 0){
			//if dead and not equal neighbor
			if(this-> value == '.' && !this->isEqual(*cellPtr)){
				aliveNeighbors++;
			}
			//if alive and equal neighbor
			else if(this-> value == '*' && this->isEqual(*cellPtr)){
				aliveNeighbors++;
			}
		}
	}
	if(value == '.'){
		if(aliveNeighbors == 1 || aliveNeighbors == 3){
			newValue = age;
		}
		else{
			newValue = '.';
		}
	}
	else{
		if(aliveNeighbors == 0 || aliveNeighbors == 2 || aliveNeighbors == 4){
			newValue = '.';
		}
		else{
			age++;	
			if(age>=9){
				newValue = '+';
			}
			else{
				newValue = age;
			}
		}
	}
}

// -------------
// Cell Methods
// -------------

void Cell::update(vector<AbstractCell*> neighbors, int row, int col, int width, int height){
	
}
