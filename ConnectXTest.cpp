/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"

class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck)
{

  ConnectX add (2,0,2);
  add.showBoard();
	ASSERT_TRUE(true);
}

TEST(ConnectXTest, INvalid_towin_test)
{
  ConnectX add (10,10,100000);
	ASSERT_TRUE(true);
}


TEST(ConnectXTest, Place_Peice){

  ConnectX add (6,6,3);
  add.placePiece(0);
  add.showBoard();
  add.placePiece(0);
  add.showBoard();
  ASSERT_EQ(2,add.at(0,5));//Initial Player is BLACK=2
  ASSERT_EQ(1,add.at(0,4));//Initial Player is WHITE=1
}


TEST(ConnectXTest, invalid_input){
  ConnectX add (3,3,-1);
  ASSERT_EQ(-1,add.at(7,7));
  ASSERT_EQ(-1,add.at(8,8));
}


TEST(ConnectXTest, Valid_input){
  ConnectX add (6,6,3);
  ASSERT_EQ(0,add.at(5,5));
  ASSERT_EQ(0,add.at(0,0));

}

TEST(ConnectXTest, INBound_INVALID_LOC){

  ConnectX add (-1,6,3);

  ASSERT_EQ(-1,add.at(-1,-1));//invalid location outBoubd
  ASSERT_EQ(-1,add.at(-2,-5));//invalid location outBoubd
}


TEST(ConnectXTest, INBound_LOC){
  ConnectX add (11,11,5);
  ASSERT_EQ(0,add.at(1,1));//Valid location EMPTY
  ASSERT_EQ(0,add.at(1,1));//Valid location EMPTY

}


TEST(ConnectXTest, Initial_TURN){
  ConnectX add (6,6,3);
//  a.showBoard();
  ASSERT_EQ(2,add.whoseTurn());//Initial Player is BLACK=2

}

TEST(ConnectXTest, INVALID_PLACE_PEICE){
  ConnectX add (6,6,3);
  //add.placePiece(9);
  add.placePiece(-3);
//  a.showBoard();
  ASSERT_EQ(-1,add.at(0,9));//Invalid placePiece -1
  ASSERT_EQ(1,add.whoseTurn());//Second Player is WHITE=1
}

TEST(ConnectXTest, Toggle_Turn){
  ConnectX add (6,6,3);
  add.placePiece(9);
//  a.showBoard();
  ASSERT_EQ(-1,add.at(0,9));//Invalid placePiece -1
  ASSERT_EQ(1,add.whoseTurn());//Second Player is WHITE=1
}
