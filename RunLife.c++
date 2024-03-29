/* @file RunLife.c++
* @brief The file that reads input and runs Life
*/

#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range

#include "Life.h"


// ----
// main
// ----

/**
 * The main method. Reads input and runs Life.
 */
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


    cout << "*** Life<" << cellType << "> " << rows << "x" << cols << " ***" << endl;
    cout << endl;

    if(cellType.compare( "FredkinCell") == 0){
      Life<FredkinCell> life(cols, rows);
      for(int r = 0; r < rows; r++){
        getline(cin, line);
        for(int c = 0; c < cols; c++){
          FredkinCell cell(line.at(c));
          life.addCell(cell);
        }
      }
      for(int i = 0; i < steps+1; i++){
        if(i%outputFreq == 0){
          cout << "Generation = " << i << ", " << life <<endl;
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
      for(int i = 0; i < steps+1; i++){
        if(i%outputFreq == 0){
          cout << "Generation = " << i << ", " << life <<endl;
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
      for(int i = 0; i < steps+1; i++){
        if(i%outputFreq == 0){
          cout << "Generation = " << i << ", " << life <<endl;
        }
        life.step();
      }
    }
    getline(cin, line);
  }
}
