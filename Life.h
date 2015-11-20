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

ostream& operator << (ostream& o, AbstractCell* cell);

template<typename T>
class Life {

	private:
		int width, height;
		vector<T*> world;
		vector<T> cells;

		FRIEND_TEST(LifeTests, constructor_1);	
		FRIEND_TEST(LifeTests, addCell_1);	
		FRIEND_TEST(LifeTests, addCell_2);	
		FRIEND_TEST(LifeTests, addCell_3);	
		FRIEND_TEST(LifeTests, step_1);	
		FRIEND_TEST(LifeTests, step_2);	
		FRIEND_TEST(LifeTests, step_3);	
		FRIEND_TEST(LifeTests, step_4);	

		FRIEND_TEST(LifeTests, begin_1);	
		FRIEND_TEST(LifeTests, begin_2);	
		FRIEND_TEST(LifeTests, begin_3);	
		FRIEND_TEST(LifeTests, begin_4);	
		FRIEND_TEST(LifeTests, begin_5);	

		FRIEND_TEST(LifeTests, end_1);	
		FRIEND_TEST(LifeTests, end_2);	
		FRIEND_TEST(LifeTests, end_3);	

		FRIEND_TEST(LifeTests, at_1);	
		FRIEND_TEST(LifeTests, at_2);	
		FRIEND_TEST(LifeTests, at_3);	

		FRIEND_TEST(LifeTests, print_1);	
		FRIEND_TEST(LifeTests, print_2);	
		FRIEND_TEST(LifeTests, print_3);	
		FRIEND_TEST(LifeTests, print_4);	
	public:

		/**
         * @param w the width of the board
         * @param h the height of the board
         *
         * Constructor for Life.
         */
		Life(int w, int h): width(w), height(h){

		}

		/**
         * @param cell the AbstractCell to add
         *
         * Adds a cell to the vector Cell. Once all cells have been added, stores a 
         * list of pointers for iteration purposes.
         */
		void addCell(T cell){
			cells.push_back(cell);
			if(cells.size()==height*width){
				for(int r = 0; r < height; ++r){
					for(int c = 0; c < width; c++){
						world.push_back(&cells[r*width + c]);
					}
				}
			}
		}

		/**
         * Runs the calculations for all AbstractCells inside of Life. Stores a new value for all of the cells inside
         * each cell's newValue, and updates all values to match the new ones once everything has been calculated.
         */
		void step(){
			for(int r = 0; r < height; ++r){
				for(int c = 0; c < width; c++){
					vector<AbstractCell*> neighbors;
					for (int rn = -1; rn < 2; ++rn){
						for (int cn = -1; cn < 2; ++cn){
							int rPos = r+rn;
							int cPos = c+cn;
							if(rn!=0 || cn!=0){
								if(rPos > -1 && rPos < height && cPos > -1 && cPos < width){
									neighbors.push_back(at(rPos,cPos));
								}else{
									neighbors.push_back(0);
								}
							}
						}
					}
					at(r,c)->update(neighbors);
				}
			}

			for(int r = 0; r < height; r++){
				for(int c = 0; c < width; c++){
					at(r,c) -> toNewValue();
				}
			}
		}

		/**
         * @return an iterator to the start of the world vector
		 *
		 * Method that allows Life to be iterable from the beginning
         */
		typename vector<T*>::iterator begin(){
			return world.begin();
		}

		/**
         * @return an iterator to the end of the world vector
		 *
		 * Method that allows Life to be iterable to the end
         */
		typename vector<T*>::iterator end(){
			return world.end();
		}

		/**
         * @param row the row value to search the world for
         * @param col the column value to search the world for
         * @return the pointer to a location of a specified AbstractCell
		 *
		 * Allows the user to search a specified row col spot in Life for an AbstractCell.
         */
		T*& at(int row, int col){
			return world[row*width + col];
		}

		/**
         * @param o the ostream to print out to
         * @param life the instance of life to output
         * @return the output stream that contains the output of life
		 *
		 * Iterates through the life grid and prints out every cell's value
         */
		friend ostream& operator << (ostream& o, Life& life){
			int pop = 0;
			for(int r = 0; r < life.height; r++) {
				for(int c = 0; c < life.width; c++) {
					if((life.at(r, c))->isAlive()){
						pop++;
					}
				}
			}
			o << "Population = " << pop << "." << endl;
			for(int r = 0; r < life.height; r++) {
				for(int c = 0; c < life.width; c++) {
					AbstractCell* cell = life.at(r, c);
					o << cell;
				}
				o << endl;
			}
			return o;
		}
};

class AbstractCell{
	protected:
		char value;
		char newValue;

		FRIEND_TEST(ConwayCellTests, constructor_1);
		FRIEND_TEST(ConwayCellTests, constructor_2);
		FRIEND_TEST(ConwayCellTests, update_1);
		FRIEND_TEST(ConwayCellTests, update_2);
		FRIEND_TEST(ConwayCellTests, update_3);
		FRIEND_TEST(ConwayCellTests, update_4);
		FRIEND_TEST(ConwayCellTests, update_5);
		FRIEND_TEST(ConwayCellTests, update_6);
		FRIEND_TEST(ConwayCellTests, update_7);
		FRIEND_TEST(ConwayCellTests, update_8);
		FRIEND_TEST(ConwayCellTests, update_9);
		FRIEND_TEST(ConwayCellTests, update_10);
		FRIEND_TEST(ConwayCellTests, isAlive_3);
		FRIEND_TEST(ConwayCellTests, isAlive_4);
		FRIEND_TEST(ConwayCellTests, isNewAlive_1);
		FRIEND_TEST(ConwayCellTests, isNewAlive_2);
		FRIEND_TEST(ConwayCellTests, isNewAlive_3);
		FRIEND_TEST(ConwayCellTests, isNewAlive_4);
		FRIEND_TEST(ConwayCellTests, clone_1);
		FRIEND_TEST(ConwayCellTests, clone_3);

		FRIEND_TEST(FredkinCellTests, constructor_1);
		FRIEND_TEST(FredkinCellTests, constructor_2);
		FRIEND_TEST(FredkinCellTests, update_1);
		FRIEND_TEST(FredkinCellTests, update_2);
		FRIEND_TEST(FredkinCellTests, update_3);
		FRIEND_TEST(FredkinCellTests, update_4);
		FRIEND_TEST(FredkinCellTests, update_5);
		FRIEND_TEST(FredkinCellTests, update_6);
		FRIEND_TEST(FredkinCellTests, update_7);
		FRIEND_TEST(FredkinCellTests, update_8);
		FRIEND_TEST(FredkinCellTests, update_9);
		FRIEND_TEST(FredkinCellTests, update_10);
		FRIEND_TEST(FredkinCellTests, update_11);
		FRIEND_TEST(FredkinCellTests, update_12);
		FRIEND_TEST(FredkinCellTests, update_13);
		FRIEND_TEST(FredkinCellTests, update_14);
		FRIEND_TEST(FredkinCellTests, update_15);
		FRIEND_TEST(FredkinCellTests, update_16);
		FRIEND_TEST(FredkinCellTests, isAlive_3);
		FRIEND_TEST(FredkinCellTests, isAlive_4);
		FRIEND_TEST(FredkinCellTests, isAlive_5);
		FRIEND_TEST(FredkinCellTests, isAlive_6);
		FRIEND_TEST(FredkinCellTests, isNewAlive_1);
		FRIEND_TEST(FredkinCellTests, isNewAlive_2);
		FRIEND_TEST(FredkinCellTests, isNewAlive_3);
		FRIEND_TEST(FredkinCellTests, isNewAlive_4);
		FRIEND_TEST(FredkinCellTests, isNewAlive_5);
		FRIEND_TEST(FredkinCellTests, isNewAlive_6);
		FRIEND_TEST(FredkinCellTests, isNewAlive_7);
		FRIEND_TEST(FredkinCellTests, clone_1);
		FRIEND_TEST(FredkinCellTests, clone_3);
		FRIEND_TEST(FredkinCellTests, clone_5);
		FRIEND_TEST(FredkinCellTests, clone_6);

		FRIEND_TEST(AbstractCellTests, constructor_1);
		FRIEND_TEST(AbstractCellTests, print_1);
		FRIEND_TEST(AbstractCellTests, print_2);

	public:
		AbstractCell(char v): value(v), newValue(-1){};
		virtual ~AbstractCell(){};
		virtual void update(vector<AbstractCell*> neighbors) = 0;
		virtual int isAlive() = 0;
		virtual int isNewAlive() const= 0;
		virtual void toNewValue();
		virtual AbstractCell* clone() const = 0;
		friend ostream& operator << (ostream& o, AbstractCell* cell);
};

class ConwayCell : public AbstractCell{
	public:
		ConwayCell(char v): AbstractCell(v) {};
		void update(vector<AbstractCell*> neighbors);
		int isAlive();
		int isNewAlive() const;
		AbstractCell* clone() const;
};

class FredkinCell : public AbstractCell{
	private:
		int age;

		FRIEND_TEST(FredkinCellTests, constructor_1);
		FRIEND_TEST(FredkinCellTests, constructor_2);
		FRIEND_TEST(FredkinCellTests, isAlive_5);
		FRIEND_TEST(FredkinCellTests, isAlive_6);
		FRIEND_TEST(FredkinCellTests, isNewAlive_5);
		FRIEND_TEST(FredkinCellTests, isNewAlive_6);
		FRIEND_TEST(FredkinCellTests, isNewAlive_7);
		FRIEND_TEST(FredkinCellTests, clone_1);
		FRIEND_TEST(FredkinCellTests, clone_3);
		FRIEND_TEST(FredkinCellTests, clone_5);
		FRIEND_TEST(FredkinCellTests, clone_6);
	public:
		FredkinCell(char v): AbstractCell(v), age(0) {};	
		void update(vector<AbstractCell*> neighbors);
		int isAlive();
		int isNewAlive() const;
		AbstractCell* clone() const;
};

class Cell : public AbstractCell{
	private:
		AbstractCell* cell;
	public:
		Cell(char v): AbstractCell(v){
			cell = new FredkinCell(v);
		};
		Cell(const Cell& rhs):AbstractCell(rhs){
			cell = rhs.cell->clone();
		};
		~Cell(){
			delete cell;
		}
		void update(vector<AbstractCell*> neighbors);
		int isAlive();
		int isNewAlive() const;
		AbstractCell* clone() const;
		void toNewValue();
};

#endif // Life_h
