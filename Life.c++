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

ostream& operator << (ostream& o, AbstractCell& cell){
	return o;
}

// -------------
// ConwayCell Methods
// -------------

void ConwayCell::update(vector<AbstractCell*> neighbors, int row, int col, int width, int height){

}

// -------------
// FredkinCell Methods
// -------------

void FredkinCell::update(vector<AbstractCell*> neighbors, int row, int col, int width, int height){
	
}

// -------------
// Cell Methods
// -------------

void Cell::update(vector<AbstractCell*> neighbors, int row, int col, int width, int height){
	
}
