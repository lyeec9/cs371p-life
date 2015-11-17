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

        cout << "cell type \"" + cellType + "\""<<endl;
        cout << "compare with fredkin cell" + to_string(cellType.compare("FredkinCell") ) << endl;
        cout << "rows" + to_string(rows) <<endl;
        cout << "cols" + to_string(cols) <<endl;
        cout << "steps" + to_string(steps) <<endl;
        cout << "outputFreq" + to_string(outputFreq) <<endl;
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

    	if(cellType.compare( "FredkinCell") == 0){
    		Life<FredkinCell> life(cols, rows);
    		for(int r = 0; r < rows; r++){
    			getline(cin, line);
    			for(int c = 0; c < cols; c++){
    				FredkinCell cell(line.at(c));
					life.addCell(cell);
				}
    		}
    		for(int i = 0; i < steps; i++){
                if(i%outputFreq == 0){
                    cout << life <<endl;
                }
    			life.step();
    		}
    	}
    	else if(cellType.compare( "ConwayCell")  == 0){
            Life<ConwayCell> life(cols, rows);
            for(int r = 0; r < rows; r++){
    			getline(cin, line);
    			for(int c = 0; c < cols; c++){
    				ConwayCell cell(line.at(c));
					life.addCell(cell);
				}
    		}
    		for(int i = 0; i < steps; i++){

                //I swapped the order of print and step for correctness
                //However, if you leave step here without the print, step still breaks
                //on the first iteration. 
                if(i%outputFreq == 0){
                    cout << life <<endl;
                }
    			life.step();
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
                if(i%outputFreq == 0){
                    cout << life <<endl;
                }
    			life.step();
    		}
    	}
    	getline(cin, line);
    }
}

