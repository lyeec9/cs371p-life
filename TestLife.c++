/** @file TestDarwin.c++
 *  @brief The file containing the unit tests for methods in Darwin.h
 */

// ------------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2015
// Glenn P. Downing
// ------------------------------------

// --------
// includes
// --------

#include "gtest/gtest.h"

#include "Life.h"

// --------------
// LifeTests
// --------------

TEST(LifeTests, constructor_1) {
	int width = 10;
	int height = 20;
	Life<Cell> life(width, height);
	ASSERT_EQ(width, life.width);
	ASSERT_EQ(height, life.height);
}



TEST(LifeTests, addCell_1) {
	int width = 1;
	int height = 2;
	Life<ConwayCell> life(width, height);
	ConwayCell cell_1('.');
	ConwayCell cell_2 = '*';
	life.addCell(cell_1);
	life.addCell(cell_2);
	ASSERT_EQ(2, life.cells.size());
	ASSERT_EQ(2, life.world.size());
	ASSERT_EQ(life.world.at(0),&life.cells.at(0));
	ASSERT_EQ(life.world.at(1),&life.cells.at(1));
	ASSERT_FALSE(life.cells.at(0).isAlive());
	ASSERT_TRUE(life.cells.at(1).isAlive());
}

TEST(LifeTests, addCell_2) {
	int width = 1;
	int height = 3;
	Life<FredkinCell> life(width, height);
	FredkinCell cell_1('-');
	FredkinCell cell_2('4');
	life.addCell(cell_1);
	life.addCell(cell_2);
	ASSERT_EQ(2, life.cells.size());
	ASSERT_EQ(0, life.world.size());
	ASSERT_FALSE(life.cells.at(0).isAlive());
	ASSERT_TRUE(life.cells.at(1).isAlive());
}

TEST(LifeTests, addCell_3) {
	int width = 1;
	int height = 3;
	Life<Cell> life(width, height);
	Cell cell_1('-');
	Cell cell_2('0');
	Cell cell_3('-');
	life.addCell(cell_1);
	life.addCell(cell_2);
	life.addCell(cell_3);
	ASSERT_EQ(3, life.cells.size());
	ASSERT_EQ(3, life.world.size());
	ASSERT_FALSE(life.cells.at(0).isAlive());
	ASSERT_TRUE(life.cells.at(1).isAlive());
	ASSERT_FALSE(life.cells.at(2).isAlive());
}



TEST(LifeTests, step_1) {
	int width = 1;
	int height = 1;
	Life<ConwayCell> life(width, height);
	ConwayCell cell_1('.');
	life.addCell(cell_1);
	ASSERT_FALSE(life.cells.at(0).isAlive());
	life.step();
	ASSERT_FALSE(life.cells.at(0).isAlive());
}

TEST(LifeTests, step_2) {
	int width = 2;
	int height = 2;
	Life<ConwayCell> life(width, height);
	ConwayCell cell_1('.');
	ConwayCell cell_2('*');
	ConwayCell cell_3('*');
	ConwayCell cell_4('*');
	life.addCell(cell_1);
	life.addCell(cell_2);
	life.addCell(cell_3);
	life.addCell(cell_4);
	ASSERT_FALSE(life.cells.at(0).isAlive());
	ASSERT_TRUE(life.cells.at(1).isAlive());
	ASSERT_TRUE(life.cells.at(2).isAlive());
	ASSERT_TRUE(life.cells.at(3).isAlive());;

	ASSERT_EQ(4, life.cells.size());
	ASSERT_EQ(4, life.world.size());

	life.step();

	ASSERT_TRUE(life.cells.at(0).isAlive());
	ASSERT_TRUE(life.cells.at(1).isAlive());
	ASSERT_TRUE(life.cells.at(2).isAlive());
	ASSERT_TRUE(life.cells.at(3).isAlive());;
}


TEST(LifeTests, step_3) {
	int width = 2;
	int height = 2;
	Life<FredkinCell> life(width, height);
	FredkinCell cell_1('-');
	FredkinCell cell_2('0');
	FredkinCell cell_3('0');
	FredkinCell cell_4('-');
	life.addCell(cell_1);
	life.addCell(cell_2);
	life.addCell(cell_3);
	life.addCell(cell_4);
	ASSERT_FALSE(life.cells.at(0).isAlive());
	ASSERT_TRUE(life.cells.at(1).isAlive());
	ASSERT_TRUE(life.cells.at(2).isAlive());
	ASSERT_FALSE(life.cells.at(3).isAlive());;

	ASSERT_EQ(4, life.cells.size());
	ASSERT_EQ(4, life.world.size());

	life.step();
	life.step();
	life.step();

	ASSERT_FALSE(life.cells.at(0).isAlive());
	ASSERT_FALSE(life.cells.at(1).isAlive());
	ASSERT_FALSE(life.cells.at(2).isAlive());
	ASSERT_FALSE(life.cells.at(3).isAlive());
}

TEST(LifeTests, step_4) {
	int width = 2;
	int height = 2;
	Life<Cell> life(width, height);
	Cell cell_1('-');
	Cell cell_2('0');
	Cell cell_3('0');
	Cell cell_4('-');
	life.addCell(cell_1);
	life.addCell(cell_2);
	life.addCell(cell_3);
	life.addCell(cell_4);
	ASSERT_FALSE(life.cells.at(0).isAlive());
	ASSERT_TRUE(life.cells.at(1).isAlive());
	ASSERT_TRUE(life.cells.at(2).isAlive());
	ASSERT_FALSE(life.cells.at(3).isAlive());;

	ASSERT_EQ(4, life.cells.size());
	ASSERT_EQ(4, life.world.size());

	life.step();
	life.step();
	life.step();

	ASSERT_FALSE(life.cells.at(0).isAlive());
	ASSERT_FALSE(life.cells.at(1).isAlive());
	ASSERT_FALSE(life.cells.at(2).isAlive());
	ASSERT_FALSE(life.cells.at(3).isAlive());
}


TEST(LifeTests, begin_1){
	int width = 2;
	int height = 2;
	Life<Cell> life(width, height);
	Cell cell_1('-');
	Cell cell_2('0');
	Cell cell_3('0');
	Cell cell_4('-');
	life.addCell(cell_1);
	life.addCell(cell_2);
	life.addCell(cell_3);
	life.addCell(cell_4);
	ASSERT_FALSE ((*life.begin()) -> isAlive() );
}

TEST(LifeTests, begin_2){
	int width = 1;
	int height = 1;
	Life<Cell> life(width, height);
	Cell cell_1('0');
	life.addCell(cell_1);
	ASSERT_TRUE ((*life.begin()) -> isAlive() );
}

TEST(LifeTests, begin_3){
	int width = 1;
	int height = 1;
	Life<ConwayCell> life(width, height);
	ConwayCell cell_1('*');
	life.addCell(cell_1);
	ASSERT_TRUE ((*life.begin()) -> isAlive() );
}

TEST(LifeTests, begin_4){
	int width = 1;
	int height = 1;
	Life<ConwayCell> life(width, height);
	ConwayCell cell_1('.');
	life.addCell(cell_1);
	ASSERT_FALSE ((*life.begin()) -> isAlive() );
}

TEST(LifeTests, begin_5){
	int width = 1;
	int height = 3;
	Life<ConwayCell> life(width, height);
	ConwayCell cell_1('.');
	ConwayCell cell_2('.');
	ConwayCell cell_3('*');
	life.addCell(cell_1);
	life.addCell(cell_2);
	life.addCell(cell_3);
	ASSERT_FALSE ((*life.begin()) -> isAlive() );
	ASSERT_FALSE (life.begin()[1] -> isAlive() );
	ASSERT_TRUE (life.begin()[2] -> isAlive() );
}


TEST(LifeTests, end_1){
	int width = 2;
	int height = 2;
	Life<ConwayCell> life(width, height);
	ConwayCell cell_1('.');
	ConwayCell cell_2('.');
	ConwayCell cell_3('.');
	ConwayCell cell_4('.');
	life.addCell(cell_1);
	life.addCell(cell_2);
	life.addCell(cell_3);
	life.addCell(cell_4);
	for(std::vector<ConwayCell*>::iterator it = life.begin() ; it != life.end(); ++it){
		ASSERT_FALSE( (*it)->isAlive() );
	}

}

TEST(LifeTests, end_2){
	int width = 2;
	int height = 1;
	Life<ConwayCell> life(width, height);
	ConwayCell cell_1('.');
	ConwayCell cell_2('*');
	life.addCell(cell_1);
	life.addCell(cell_2);
	std::vector<ConwayCell*>::iterator it = life.begin();
	ASSERT_FALSE( (*it)->isAlive() );
	it++;
	ASSERT_TRUE( (*it)->isAlive() );

}

TEST(LifeTests, end_3){
	int width = 1;
	int height = 1;
	Life<ConwayCell> life(width, height);
	ConwayCell cell_1('.');
	life.addCell(cell_1);
	ASSERT_FALSE( life.end() == life.begin());
}



TEST(LifeTests, at_1){
	int width = 2;
	int height = 2;
	Life<ConwayCell> life(width, height);
	ConwayCell cell_1('.');
	ConwayCell cell_2('*');
	ConwayCell cell_3('*');
	ConwayCell cell_4('.');
	life.addCell(cell_1);
	life.addCell(cell_2);
	life.addCell(cell_3);
	life.addCell(cell_4);
	ASSERT_FALSE(life.at(0,0) -> isAlive());
	ASSERT_TRUE(life.at(0,1) -> isAlive());
	ASSERT_TRUE(life.at(1,0) -> isAlive());
	ASSERT_FALSE(life.at(1,1) -> isAlive());

}

TEST(LifeTests, at_2){
	int width = 2;
	int height = 1;
	Life<FredkinCell> life(width, height);
	FredkinCell cell_1('-');
	FredkinCell cell_2('1');
	life.addCell(cell_1);
	life.addCell(cell_2);
	ASSERT_FALSE(life.at(0,0) -> isAlive());
	ASSERT_TRUE(life.at(0,1) -> isAlive());

}

TEST(LifeTests, at_3){
	int width = 1;
	int height = 1;
	Life<Cell> life(width, height);
	Cell cell_1('-');
	life.addCell(cell_1);
	ASSERT_FALSE( life.at(0,0) -> isAlive());
}


TEST(LifeTests, print_1){
	int width = 1;
	int height = 1;
	Life<Cell> life(width, height);
	Cell cell_1('-');
	life.addCell(cell_1);
	ostringstream oss;
	oss << life;
	ASSERT_EQ("Population = 0.\n-\n",oss.str());
}

TEST(LifeTests, print_2){
	int width = 2;
	int height = 2;
	Life<ConwayCell> life(width, height);
	ConwayCell cell_1('.');
	ConwayCell cell_2('*');
	ConwayCell cell_3('*');
	ConwayCell cell_4('.');
	life.addCell(cell_1);
	life.addCell(cell_2);
	life.addCell(cell_3);
	life.addCell(cell_4);
	ostringstream oss;
	oss << life;
	ASSERT_EQ("Population = 2.\n.*\n*.\n",oss.str());
}

TEST(LifeTests, print_3){
	int width = 1;
	int height = 2;
	Life<Cell> life(width, height);
	Cell cell_1('0');
	Cell cell_2('0');
	life.addCell(cell_1);
	life.addCell(cell_2);
	life.step();
	ostringstream oss;
	oss << life;

	ASSERT_EQ("Population = 2.\n1\n1\n",oss.str());
}

TEST(LifeTests, print_4){
	int width = 2;
	int height = 2;
	Life<FredkinCell> life(width, height);
	FredkinCell cell_1('-');
	FredkinCell cell_2('0');
	FredkinCell cell_3('0');
	FredkinCell cell_4('-');
	life.addCell(cell_1);
	life.addCell(cell_2);
	life.addCell(cell_3);
	life.addCell(cell_4);
	ostringstream oss;
	oss << life;
	ASSERT_EQ("Population = 2.\n-0\n0-\n",oss.str());
}





// --------------
// AbstractCell
// --------------

TEST(AbstractCellTests, constructor_1){
	Cell cell_1('-');
	ASSERT_EQ('-',cell_1.value);
	ASSERT_EQ(-1,cell_1.newValue);
}


TEST(AbstractCellTests, print_1){
	Cell cell_1('-');
	ostringstream oss;
	oss << &cell_1;
	ASSERT_EQ("-",oss.str());
}

TEST(AbstractCellTests, print_2){
	ConwayCell cell_1('.');
	ostringstream oss;
	oss << &cell_1;
	ASSERT_EQ(".",oss.str());
}




// --------------
// ConwayCellTests
// --------------

TEST(ConwayCellTests, constructor_1) {
	ConwayCell cc('*');
	ASSERT_EQ(cc.value, '*');
	ASSERT_NE(cc.value, '.');
}

TEST(ConwayCellTests, constructor_2) {
	ConwayCell cc('.');
	ASSERT_EQ(cc.value, '.');
	ASSERT_NE(cc.value, '*');
}

TEST(ConwayCellTests, update_1) {
	ConwayCell cc('.');
	vector<AbstractCell*> neighbors;
	ConwayCell cc1('.');
	ConwayCell cc2('.');
	ConwayCell cc3('.');
	ConwayCell cc4('.');
	ConwayCell cc5('.');
	ConwayCell cc6('.');
	ConwayCell cc7('.');
	ConwayCell cc8('.');
	neighbors.push_back(&cc1);
	neighbors.push_back(&cc2);
	neighbors.push_back(&cc3);
	neighbors.push_back(&cc4);
	neighbors.push_back(&cc5);
	neighbors.push_back(&cc6);
	neighbors.push_back(&cc7);
	neighbors.push_back(&cc8);
	cc.update(neighbors);
	ASSERT_EQ(cc.value, '.');
	ASSERT_EQ(cc.newValue, '.');
}

TEST(ConwayCellTests, update_2) {
	ConwayCell cc('.');
	vector<AbstractCell*> neighbors;
	ConwayCell cc1('*');
	ConwayCell cc2('*');
	ConwayCell cc3('*');
	ConwayCell cc4('*');
	ConwayCell cc5('*');
	ConwayCell cc6('*');
	ConwayCell cc7('*');
	ConwayCell cc8('*');
	neighbors.push_back(&cc1);
	neighbors.push_back(&cc2);
	neighbors.push_back(&cc3);
	neighbors.push_back(&cc4);
	neighbors.push_back(&cc5);
	neighbors.push_back(&cc6);
	neighbors.push_back(&cc7);
	neighbors.push_back(&cc8);
	cc.update(neighbors);
	ASSERT_EQ(cc.value, '.');
	ASSERT_EQ(cc.newValue, '.');
}

TEST(ConwayCellTests, update_3) {
	ConwayCell cc('.');
	vector<AbstractCell*> neighbors;
	ConwayCell cc1('.');
	ConwayCell cc2('*');
	ConwayCell cc3('.');
	ConwayCell cc4('*');
	ConwayCell cc5('*');
	ConwayCell cc6('.');
	ConwayCell cc7('*');
	ConwayCell cc8('.');
	neighbors.push_back(&cc1);
	neighbors.push_back(&cc2);
	neighbors.push_back(&cc3);
	neighbors.push_back(&cc4);
	neighbors.push_back(&cc5);
	neighbors.push_back(&cc6);
	neighbors.push_back(&cc7);
	neighbors.push_back(&cc8);
	cc.update(neighbors);
	ASSERT_EQ(cc.value, '.');
	ASSERT_EQ(cc.newValue, '.');
}

TEST(ConwayCellTests, update_4) {
	ConwayCell cc('.');
	vector<AbstractCell*> neighbors;
	ConwayCell cc1('.');
	ConwayCell cc2('*');
	ConwayCell cc3('.');
	ConwayCell cc4('*');
	ConwayCell cc5('*');
	ConwayCell cc6('.');
	ConwayCell cc7('.');
	ConwayCell cc8('*');
	neighbors.push_back(&cc1);
	neighbors.push_back(&cc2);
	neighbors.push_back(&cc3);
	neighbors.push_back(&cc4);
	neighbors.push_back(&cc5);
	neighbors.push_back(&cc6);
	neighbors.push_back(&cc7);
	neighbors.push_back(&cc8);
	cc.update(neighbors);
	ASSERT_EQ(cc.value, '.');
	ASSERT_EQ(cc.newValue, '.');
}

TEST(ConwayCellTests, update_5) {
	ConwayCell cc('.');
	vector<AbstractCell*> neighbors;
	ConwayCell cc1('*');
	ConwayCell cc2('.');
	ConwayCell cc3('*');
	ConwayCell cc4('.');
	ConwayCell cc5('.');
	ConwayCell cc6('.');
	ConwayCell cc7('.');
	ConwayCell cc8('*');
	neighbors.push_back(&cc1);
	neighbors.push_back(&cc2);
	neighbors.push_back(&cc3);
	neighbors.push_back(&cc4);
	neighbors.push_back(&cc5);
	neighbors.push_back(&cc6);
	neighbors.push_back(&cc7);
	neighbors.push_back(&cc8);
	cc.update(neighbors);
	ASSERT_EQ(cc.value, '.');
	ASSERT_EQ(cc.newValue, '*');
}

TEST(ConwayCellTests, update_6) {
	ConwayCell cc('.');
	vector<AbstractCell*> neighbors;
	ConwayCell cc1('.');
	ConwayCell cc2('.');
	ConwayCell cc3('.');
	ConwayCell cc4('.');
	ConwayCell cc5('.');
	ConwayCell cc6('*');
	ConwayCell cc7('.');
	ConwayCell cc8('*');
	neighbors.push_back(&cc1);
	neighbors.push_back(&cc2);
	neighbors.push_back(&cc3);
	neighbors.push_back(&cc4);
	neighbors.push_back(&cc5);
	neighbors.push_back(&cc6);
	neighbors.push_back(&cc7);
	neighbors.push_back(&cc8);
	cc.update(neighbors);
	ASSERT_EQ(cc.value, '.');
	ASSERT_EQ(cc.newValue, '.');
}

TEST(ConwayCellTests, update_7) {
	ConwayCell cc('*');
	vector<AbstractCell*> neighbors;
	ConwayCell cc1('.');
	ConwayCell cc2('.');
	ConwayCell cc3('.');
	ConwayCell cc4('.');
	ConwayCell cc5('.');
	ConwayCell cc6('.');
	ConwayCell cc7('.');
	ConwayCell cc8('*');
	neighbors.push_back(&cc1);
	neighbors.push_back(&cc2);
	neighbors.push_back(&cc3);
	neighbors.push_back(&cc4);
	neighbors.push_back(&cc5);
	neighbors.push_back(&cc6);
	neighbors.push_back(&cc7);
	neighbors.push_back(&cc8);
	cc.update(neighbors);
	ASSERT_EQ(cc.value, '*');
	ASSERT_EQ(cc.newValue, '.');
}

TEST(ConwayCellTests, update_8) {
	ConwayCell cc('*');
	vector<AbstractCell*> neighbors;
	ConwayCell cc1('.');
	ConwayCell cc2('.');
	ConwayCell cc3('.');
	ConwayCell cc4('.');
	ConwayCell cc5('.');
	ConwayCell cc6('*');
	ConwayCell cc7('.');
	ConwayCell cc8('*');
	neighbors.push_back(&cc1);
	neighbors.push_back(&cc2);
	neighbors.push_back(&cc3);
	neighbors.push_back(&cc4);
	neighbors.push_back(&cc5);
	neighbors.push_back(&cc6);
	neighbors.push_back(&cc7);
	neighbors.push_back(&cc8);
	cc.update(neighbors);
	ASSERT_EQ(cc.value, '*');
	ASSERT_EQ(cc.newValue, '*');
}

TEST(ConwayCellTests, update_9) {
	ConwayCell cc('*');
	vector<AbstractCell*> neighbors;
	ConwayCell cc1('*');
	ConwayCell cc2('.');
	ConwayCell cc3('*');
	ConwayCell cc4('.');
	ConwayCell cc5('.');
	ConwayCell cc6('.');
	ConwayCell cc7('.');
	ConwayCell cc8('*');
	neighbors.push_back(&cc1);
	neighbors.push_back(&cc2);
	neighbors.push_back(&cc3);
	neighbors.push_back(&cc4);
	neighbors.push_back(&cc5);
	neighbors.push_back(&cc6);
	neighbors.push_back(&cc7);
	neighbors.push_back(&cc8);
	cc.update(neighbors);
	ASSERT_EQ(cc.value, '*');
	ASSERT_EQ(cc.newValue, '*');
}

TEST(ConwayCellTests, update_10) {
	ConwayCell cc('*');
	vector<AbstractCell*> neighbors;
	ConwayCell cc1('*');
	ConwayCell cc2('.');
	ConwayCell cc3('*');
	ConwayCell cc4('.');
	ConwayCell cc5('.');
	ConwayCell cc6('*');
	ConwayCell cc7('.');
	ConwayCell cc8('*');
	neighbors.push_back(&cc1);
	neighbors.push_back(&cc2);
	neighbors.push_back(&cc3);
	neighbors.push_back(&cc4);
	neighbors.push_back(&cc5);
	neighbors.push_back(&cc6);
	neighbors.push_back(&cc7);
	neighbors.push_back(&cc8);
	cc.update(neighbors);
	ASSERT_EQ(cc.value, '*');
	ASSERT_EQ(cc.newValue, '.');
}

TEST(ConwayCellTests, isAlive_1) {
	ConwayCell cc('*');
	ASSERT_TRUE(cc.isAlive());
}

TEST(ConwayCellTests, isAlive_2) {
	ConwayCell cc('.');
	ASSERT_FALSE(cc.isAlive());
}

TEST(ConwayCellTests, isAlive_3) {
	ConwayCell cc('*');
	cc.newValue = '.';
	ASSERT_TRUE(cc.isAlive());
}

TEST(ConwayCellTests, isAlive_4) {
	ConwayCell cc('.');
	cc.newValue = '*';
	ASSERT_FALSE(cc.isAlive());
}

TEST(ConwayCellTests, isNewAlive_1) {
	ConwayCell cc('*');
	cc.newValue = '*';
	ASSERT_TRUE(cc.isNewAlive());
}

TEST(ConwayCellTests, isNewAlive_2) {
	ConwayCell cc('*');
	cc.newValue = '.';
	ASSERT_FALSE(cc.isNewAlive());
}

TEST(ConwayCellTests, isNewAlive_3) {
	ConwayCell cc('.');
	cc.newValue = '*';
	ASSERT_TRUE(cc.isNewAlive());
}

TEST(ConwayCellTests, isNewAlive_4) {
	ConwayCell cc('.');
	cc.newValue = '.';
	ASSERT_FALSE(cc.isNewAlive());
}

TEST(ConwayCellTests, clone_1) {
	ConwayCell cc('*');
	AbstractCell* cc2 = cc.clone();
	ASSERT_EQ(cc.value, cc2->value);
	ASSERT_EQ(cc.newValue, cc2->newValue);
	delete cc2;
}

TEST(ConwayCellTests, clone_2) {
	ConwayCell cc('*');
	AbstractCell* cc2 = cc.clone();
	ASSERT_EQ(cc.isAlive(), cc2->isAlive());
	ASSERT_EQ(cc.isNewAlive(), cc2->isNewAlive());
	delete cc2;
}

TEST(ConwayCellTests, clone_3) {
	ConwayCell cc('.');
	AbstractCell* cc2 = cc.clone();
	ASSERT_EQ(cc.value, cc2->value);
	ASSERT_EQ(cc.newValue, cc2->newValue);
	delete cc2;
}

TEST(ConwayCellTests, clone_4) {
	ConwayCell cc('.');
	AbstractCell* cc2 = cc.clone();
	ASSERT_EQ(cc.isAlive(), cc2->isAlive());
	ASSERT_EQ(cc.isNewAlive(), cc2->isNewAlive());
	delete cc2;
}

// --------------
// FredkinCellTests
// --------------

TEST(FredkinCellTests, constructor_1) {
	FredkinCell fc('0');
	ASSERT_EQ(fc.value, '0');
	ASSERT_NE(fc.value, '-');
	ASSERT_EQ(fc.age, 0);
}

TEST(FredkinCellTests, constructor_2) {
	FredkinCell fc('-');
	ASSERT_EQ(fc.value, '-');
	ASSERT_NE(fc.value, '0');
	ASSERT_EQ(fc.age, 0);
}

TEST(FredkinCellTests, update_1) {
	FredkinCell fc('-');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('-');
	FredkinCell fc2('-');
	FredkinCell fc3('-');
	FredkinCell fc4('-');
	FredkinCell fc5('-');
	FredkinCell fc6('-');
	FredkinCell fc7('-');
	FredkinCell fc8('-');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '-');
	ASSERT_EQ(fc.newValue, '-');
}

TEST(FredkinCellTests, update_2) {
	FredkinCell fc('-');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('0');
	FredkinCell fc2('0');
	FredkinCell fc3('0');
	FredkinCell fc4('0');
	FredkinCell fc5('0');
	FredkinCell fc6('0');
	FredkinCell fc7('0');
	FredkinCell fc8('0');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '-');
	ASSERT_EQ(fc.newValue, '-');
}

TEST(FredkinCellTests, update_3) {
	FredkinCell fc('-');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('-');
	FredkinCell fc2('0');
	FredkinCell fc3('-');
	FredkinCell fc4('0');
	FredkinCell fc5('0');
	FredkinCell fc6('-');
	FredkinCell fc7('0');
	FredkinCell fc8('-');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '-');
	ASSERT_EQ(fc.newValue, '-');
}

TEST(FredkinCellTests, update_4) {
	FredkinCell fc('-');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('-');
	FredkinCell fc2('0');
	FredkinCell fc3('-');
	FredkinCell fc4('0');
	FredkinCell fc5('0');
	FredkinCell fc6('-');
	FredkinCell fc7('-');
	FredkinCell fc8('0');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '-');
	ASSERT_EQ(fc.newValue, '0');
}

TEST(FredkinCellTests, update_5) {
	FredkinCell fc('-');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('0');
	FredkinCell fc2('-');
	FredkinCell fc3('0');
	FredkinCell fc4('-');
	FredkinCell fc5('-');
	FredkinCell fc6('-');
	FredkinCell fc7('-');
	FredkinCell fc8('0');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '-');
	ASSERT_EQ(fc.newValue, '-');
}

TEST(FredkinCellTests, update_6) {
	FredkinCell fc('-');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('-');
	FredkinCell fc2('-');
	FredkinCell fc3('-');
	FredkinCell fc4('-');
	FredkinCell fc5('-');
	FredkinCell fc6('0');
	FredkinCell fc7('-');
	FredkinCell fc8('0');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '-');
	ASSERT_EQ(fc.newValue, '-');
}

TEST(FredkinCellTests, update_7) {
	FredkinCell fc('-');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('-');
	FredkinCell fc2('0');
	FredkinCell fc3('-');
	FredkinCell fc4('-');
	FredkinCell fc5('-');
	FredkinCell fc6('0');
	FredkinCell fc7('-');
	FredkinCell fc8('0');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '-');
	ASSERT_EQ(fc.newValue, '0');
}

TEST(FredkinCellTests, update_8) {
	FredkinCell fc('-');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('-');
	FredkinCell fc2('0');
	FredkinCell fc3('-');
	FredkinCell fc4('0');
	FredkinCell fc5('-');
	FredkinCell fc6('0');
	FredkinCell fc7('-');
	FredkinCell fc8('0');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '-');
	ASSERT_EQ(fc.newValue, '-');
}

TEST(FredkinCellTests, update_9) {
	FredkinCell fc('0');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('-');
	FredkinCell fc2('-');
	FredkinCell fc3('-');
	FredkinCell fc4('-');
	FredkinCell fc5('-');
	FredkinCell fc6('-');
	FredkinCell fc7('-');
	FredkinCell fc8('0');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '0');
	ASSERT_EQ(fc.newValue, '-');
}

TEST(FredkinCellTests, update_10) {
	FredkinCell fc('0');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('-');
	FredkinCell fc2('0');
	FredkinCell fc3('-');
	FredkinCell fc4('-');
	FredkinCell fc5('-');
	FredkinCell fc6('-');
	FredkinCell fc7('-');
	FredkinCell fc8('0');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '0');
	ASSERT_EQ(fc.newValue, '1');
}

TEST(FredkinCellTests, update_11) {
	FredkinCell fc('0');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('0');
	FredkinCell fc2('0');
	FredkinCell fc3('0');
	FredkinCell fc4('0');
	FredkinCell fc5('-');
	FredkinCell fc6('-');
	FredkinCell fc7('-');
	FredkinCell fc8('0');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '0');
	ASSERT_EQ(fc.newValue, '-');
}

TEST(FredkinCellTests, update_12) {
	FredkinCell fc('0');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('0');
	FredkinCell fc2('0');
	FredkinCell fc3('0');
	FredkinCell fc4('0');
	FredkinCell fc5('0');
	FredkinCell fc6('0');
	FredkinCell fc7('-');
	FredkinCell fc8('0');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '0');
	ASSERT_EQ(fc.newValue, '1');
}

TEST(FredkinCellTests, update_13) {
	FredkinCell fc('0');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('-');
	FredkinCell fc2('0');
	FredkinCell fc3('0');
	FredkinCell fc4('0');
	FredkinCell fc5('0');
	FredkinCell fc6('-');
	FredkinCell fc7('0');
	FredkinCell fc8('-');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '0');
	ASSERT_EQ(fc.newValue, '-');
}

TEST(FredkinCellTests, update_14) {
	FredkinCell fc('0');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('-');
	FredkinCell fc2('3');
	FredkinCell fc3('-');
	FredkinCell fc4('-');
	FredkinCell fc5('-');
	FredkinCell fc6('-');
	FredkinCell fc7('-');
	FredkinCell fc8('-');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '0');
	ASSERT_EQ(fc.newValue, '1');
}

TEST(FredkinCellTests, update_15) {
	FredkinCell fc('0');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('-');
	FredkinCell fc2('3');
	FredkinCell fc3('-');
	FredkinCell fc4('-');
	FredkinCell fc5('-');
	FredkinCell fc6('-');
	FredkinCell fc7('-');
	FredkinCell fc8('-');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '0');
	fc.update(neighbors);
	fc.update(neighbors);
	fc.update(neighbors);
	fc.update(neighbors);
	fc.update(neighbors);
	fc.update(neighbors);
	fc.update(neighbors);
	fc.update(neighbors);
	fc.update(neighbors);
	ASSERT_EQ(fc.newValue, '+');
}

TEST(FredkinCellTests, update_16) {
	FredkinCell fc('0');
	vector<AbstractCell*> neighbors;
	FredkinCell fc1('-');
	FredkinCell fc2('0');
	FredkinCell fc3('-');
	FredkinCell fc4('+');
	FredkinCell fc5('0');
	FredkinCell fc6('-');
	FredkinCell fc7('-');
	FredkinCell fc8('-');
	neighbors.push_back(&fc1);
	neighbors.push_back(&fc2);
	neighbors.push_back(&fc3);
	neighbors.push_back(&fc4);
	neighbors.push_back(&fc5);
	neighbors.push_back(&fc6);
	neighbors.push_back(&fc7);
	neighbors.push_back(&fc8);
	fc.update(neighbors);
	ASSERT_EQ(fc.value, '0');
	ASSERT_EQ(fc.newValue, '1');
}

TEST(FredkinCellTests, isAlive_1) {
	FredkinCell fc('0');
	ASSERT_EQ(fc.isAlive(), 1);
}

TEST(FredkinCellTests, isAlive_2) {
	FredkinCell fc('-');
	ASSERT_EQ(fc.isAlive(), 0);
}

TEST(FredkinCellTests, isAlive_3) {
	FredkinCell fc('0');
	fc.newValue = '-';
	ASSERT_EQ(fc.isAlive(), 1);
}

TEST(FredkinCellTests, isAlive_4) {
	FredkinCell fc('-');
	fc.newValue = '0';
	ASSERT_EQ(fc.isAlive(), 0);
}

TEST(FredkinCellTests, isAlive_5) {
	FredkinCell fc('0');
	fc.newValue = '-';
	fc.age = 3;
	ASSERT_EQ(fc.isAlive(), 4);
}

TEST(FredkinCellTests, isAlive_6) {
	FredkinCell fc('-');
	fc.newValue = '0';
	fc.age = 3;
	ASSERT_EQ(fc.isAlive(), 0);
}

TEST(FredkinCellTests, isNewAlive_1) {
	FredkinCell fc('0');
	fc.newValue = '0';
	ASSERT_EQ(fc.isNewAlive(), 1);
}

TEST(FredkinCellTests, isNewAlive_2) {
	FredkinCell fc('0');
	fc.newValue = '-';
	ASSERT_EQ(fc.isNewAlive(), 0);
}

TEST(FredkinCellTests, isNewAlive_3) {
	FredkinCell fc('-');
	fc.newValue = '0';
	ASSERT_EQ(fc.isNewAlive(), 1);
}

TEST(FredkinCellTests, isNewAlive_4) {
	FredkinCell fc('-');
	fc.newValue = '-';
	ASSERT_EQ(fc.isNewAlive(), 0);
}

TEST(FredkinCellTests, isNewAlive_5) {
	FredkinCell fc('-');
	fc.newValue = '-';
	fc.age = 5;
	ASSERT_EQ(fc.isNewAlive(), 0);
}

TEST(FredkinCellTests, isNewAlive_6) {
	FredkinCell fc('-');
	fc.newValue = '*';
	fc.age = 2;
	ASSERT_EQ(fc.isNewAlive(), 3);
}

TEST(FredkinCellTests, isNewAlive_7) {
	FredkinCell fc('*');
	fc.newValue = '*';
	fc.age = 1;
	ASSERT_EQ(fc.isNewAlive(), 2);
}

TEST(FredkinCellTests, clone_1) {
	FredkinCell fc('0');
	AbstractCell* fc2 = fc.clone();
	ASSERT_EQ(fc.value, fc2->value);
	ASSERT_EQ(fc.newValue, fc2->newValue);
	if (const FredkinCell* const p = dynamic_cast<const FredkinCell*>(fc2)){
		ASSERT_EQ(fc.age, p->age);
	}else{
		FAIL();
	}
	delete fc2;
}

TEST(FredkinCellTests, clone_2) {
	FredkinCell fc('0');
	AbstractCell* fc2 = fc.clone();
	ASSERT_EQ(fc.isAlive(), fc2->isAlive());
	ASSERT_EQ(fc.isNewAlive(), fc2->isNewAlive());
	delete fc2;
}

TEST(FredkinCellTests, clone_3) {
	FredkinCell fc('-');
	AbstractCell* fc2 = fc.clone();
	ASSERT_EQ(fc.value, fc2->value);
	ASSERT_EQ(fc.newValue, fc2->newValue);
	if (const FredkinCell* const p = dynamic_cast<const FredkinCell*>(fc2)){
		ASSERT_EQ(fc.age, p->age);
	}else{
		FAIL();
	}
	delete fc2;
}

TEST(FredkinCellTests, clone_4) {
	FredkinCell fc('-');
	AbstractCell* fc2 = fc.clone();
	ASSERT_EQ(fc.isAlive(), fc2->isAlive());
	ASSERT_EQ(fc.isNewAlive(), fc2->isNewAlive());
	delete fc2;
}

TEST(FredkinCellTests, clone_5) {
	FredkinCell fc('-');
	fc.age = 2;
	AbstractCell* fc2 = fc.clone();
	ASSERT_EQ(fc.value, fc2->value);
	ASSERT_EQ(fc.newValue, fc2->newValue);
	if (const FredkinCell* const p = dynamic_cast<const FredkinCell*>(fc2)){
		ASSERT_EQ(fc.age, p->age);
	}else{
		FAIL();
	}
	delete fc2;
}

TEST(FredkinCellTests, clone_6) {
	FredkinCell fc('*');
	fc.age = 2;
	AbstractCell* fc2 = fc.clone();
	ASSERT_EQ(fc.value, fc2->value);
	ASSERT_EQ(fc.newValue, fc2->newValue);
	if (const FredkinCell* const p = dynamic_cast<const FredkinCell*>(fc2)){
		ASSERT_EQ(fc.age, p->age);
	}else{
		FAIL();
	}
	delete fc2;
}