/* @file RunDarwin.c++
 * @brief The file that simulates the 4 desired boards
 */

#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range

#include "Life.h"


// ----
// main
// ----

int main () {
    using namespace std;
    string line;
    while(getline(cin,line)){
    	string cellType = line;
    	getline(cin,line);
    	int rows = stoi(line);
    	getline(cin,line);
    	int cols = stoi(line);
    	getline(cin,line);
    	int steps = stoi(line);
    	getline(cin,line);
    	int outputFreq = stoi(line);

    	/*fix scope problem
    	if(strcmp(cellType, "FredkinCell"))
    		Life<FredkinCell> life(cols, rows);
    	else if(strcmp(cellType, "ConwayCell"))
    		Life<ConwayCell> life(cols, rows);
    	else
    		Life<T> life(cols, rows);


    	for(int r = 0; r < rows; r++){
    		getline(cin, line);
    		if(strcmp(cellType, "fredkinCell"))

    		else if(strcmp(cellType, "ConwayCell"))
    			
    	}

		*/

    	if(cellType.compare( "FredkinCell")){
    		Life<FredkinCell> life(cols, rows);
    		for(int r = 0; r < rows; r++){
    			getline(cin, line);
    			for(int c = 0; c < cols; c++){
    				FredkinCell cell(line.at(c));
					life.addCell(cell);
				}
    		}
    		for(int i = 0; i < steps; i++){
    			life.step();
    			if(i%outputFreq == 0){
    				cout << life <<endl;
    			}
    		}
    	}
    	else if(cellType.compare( "ConwayCell")){
    		Life<ConwayCell> life(cols, rows);
    		for(int r = 0; r < rows; r++){
    			getline(cin, line);
    			for(int c = 0; c < cols; c++){
    				ConwayCell cell(line.at(c));
					life.addCell(cell);
				}
    		}
    		for(int i = 0; i < steps; i++){
    			life.step();
    			if(i%outputFreq == 0){
    				cout << life <<endl;
    			}
    		}
    	}
    	else{
    		Life<Cell> life(cols, rows);
    		for(int r = 0; r < rows; r++){
    			getline(cin, line);
    			for(int c = 0; c < cols; c++){
    				Cell cell(line.at(c));
					life.addCell(cell);
				}
    		}
    		for(int i = 0; i < steps; i++){
    			life.step();
    			if(i%outputFreq == 0){
    				cout << life <<endl;
    			}
    		}
    	}
    	getline(cin, line);
    }
}

