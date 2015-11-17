/* @file Darwin.h
 * @brief The header file defining all of the methods used in Darwin.c++
 */

#ifndef Life_h
#define Life_h

// --------
// includes
// --------

#include <string>   // strings
#include <iostream> //
#include <cstdlib>  //
#include <vector>   // vector
#include <unordered_map> // unordered_map
#include "gtest/gtest.h" // friend tests

using namespace std;
class AbstractCell;
class Cell;
class ConwayCell;
class FredkinCell;

ostream& operator << (ostream& o, AbstractCell& cell);

template<typename T>
class Life {
	private:
		int width, height;
		vector<T*> world;
		vector<T> cells;
	public:

		Life(int w, int h): width(w), height(h){
			
		}
		void addCell(T cell){
			world.push_back(&cell);
			cells.push_back(cell);
		}
		void step(){
			
		}

		typename vector<T*>::iterator begin(){
			return world.begin();
		}

		typename vector<T*>::iterator end(){
			return world.end();	
		}

		T*& at(int row, int col){
			return world[row*width + col];
		}

        friend ostream& operator << (ostream& o, Life& life){  	
		    for(int r = 0; r < life.height; r++) {
		        for(int c = 0; c < life.width; c++) {
		            AbstractCell* cell = life.at(c, r);
		            o << (*cell);
		        }
		        o << endl;
		    }
    		return o;
        }
};

class AbstractCell{
	protected:
		char value;
	public:
		AbstractCell(char v): value(v){};
		virtual void update(Life<AbstractCell>& life, int row, int col, 
			int width, int height) = 0;
		bool isEqual(const AbstractCell& rhs);
		friend ostream& operator << (ostream& o, AbstractCell& cell);
};

class ConwayCell : public AbstractCell{
	public:
		ConwayCell(char v): AbstractCell(v) {};
		void update(Life<AbstractCell>& life, int row, int col, 
			int width, int height);		
};

class FredkinCell : public AbstractCell{
	public:
		FredkinCell(char v): AbstractCell(v) {};
		void update(Life<AbstractCell>& life, int row, int col, 
			int width, int height);
};

class Cell : public AbstractCell{
	private:
		ConwayCell c;
		FredkinCell f;
	public:
		Cell(char v): AbstractCell(v), c(v), f(v) {};
		void update(Life<AbstractCell>& life, int row, int col, 
			int width, int height);
};

#endif // Life_h
