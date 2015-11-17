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
// Cell Methods
// -------------
ostream& operator << (ostream& o, AbstractCell& cell){
	return o;
}

void ConwayCell::update(Life<AbstractCell>& life, int row, int col, int width, int height){

}

void FredkinCell::update(Life<AbstractCell>& life, int row, int col, int width, int height){
	
}

void Cell::update(Life<AbstractCell>& life, int row, int col, int width, int height){
	
}
