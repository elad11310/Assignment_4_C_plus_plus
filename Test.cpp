//
// Created by elad on 26/05/2020.
//


#include "doctest.h"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"
#include <iostream>

using namespace WarGame;


TEST_CASE ("Moving tests") {
    Board board(8, 8);


    board[{0, 1}] = new FootSoldier(1);
    board[{0, 3}] = new FootCommander(1);
    board[{0, 5}] = new FootSoldier(1);
   board[{1, 5}] = new Sniper(1);
    board[{1, 2}] = new Paramedic(1);

    board[{7, 1}] = new Sniper(2);
    board[{7, 3}] = new FootCommander(2);
    board[{7, 5}] = new FootSoldier(2);
    board[{6, 2}] = new SniperCommander(2);
    board[{6, 5}] = new Sniper(2);

            CHECK(typeid(board[{0, 1}]) == typeid(Soldier*));

    board.move(1, {0, 1}, WarGame::Board::Up);
          CHECK(board[{1,1}]!= nullptr);
            CHECK(board[{6,2}]->getHealth()==110);
            board.move(2,{6,5},WarGame::Board::Down);
            CHECK(board[{5,5}]!= nullptr);
            CHECK(board[{0,3}]->getHealth()==100);
	CHECK_THROWS(board.move(1, {0, 3}, WarGame::Board::Down));
	CHECK_THROWS(board.move(1, {7, 3}, WarGame::Board::Up));
	board.move(2, {5, 5}, WarGame::Board::Right);
	board.move(2, {5, 6}, WarGame::Board::Right);
	CHECK_THROWS(board.move(2, {5, 7}, WarGame::Board::Right));	board.move(2, {7, 1}, WarGame::Board::Right);
CHECK_THROWS(board.move(2, {7, 2}, WarGame::Board::Right));
 board.move(2,{6,2},WarGame::Board::Down);
// paramedic is dead now
 CHECK(board[{1,2}]==nullptr);
// FootSoldier of team 1 is also dead	
CHECK(board[{0,1}]==nullptr);
// attack with sniper of team 1
board.move(1, {1, 5}, WarGame::Board::Left);
 CHECK(board[{7,3}]->getHealth()==100);
CHECK(board[{1,4}]!=nullptr);	




}

TEST_CASE ("Healing tests") {

Board board(4, 4);

    board[{0, 1}] = new FootSoldier(1);
    board[{0, 3}] = new FootCommander(1);
    board[{1, 2}] = new Paramedic(1);

    board[{3, 1}] = new Sniper(2);
    board[{3, 3}] = new FootCommander(2);
    board[{3, 2}] = new FootSoldier(2);

// moving sniper and hitting the foot commander of team 1	
board.move(2, {3, 1}, WarGame::Board::Down);
// check if the foot commander is hit
  CHECK(board[{0,3}]->getHealth()==100);

// moving right with the healer and check if heals the foot commander
board.move(1, {1, 2}, WarGame::Board::Right);
CHECK(board[{0,3}]->getHealth()==150);

CHECK_THROWS(board.move(2, {3, 3}, WarGame::Board::Left));

}

TEST_CASE ("More tests") {

Board board(5, 5);

    board[{0, 1}] = new FootSoldier(1);
    board[{0, 3}] = new FootCommander(1);
    board[{1, 2}] = new Paramedic(1);
board[{3, 4}] = new Sniper(1);


    board[{3, 1}] = new Sniper(2);
    board[{3, 3}] = new FootCommander(2);
    board[{3, 2}] = new FootSoldier(2);
board[{4, 0}] = new SniperCommander(2);
board[{4, 3}] = new ParamedicCommander(2);

// moving sniper and checking if moved
board.move(2, {4, 0}, WarGame::Board::Right);
CHECK(board[{4,0}]==nullptr);
CHECK(board[{4,1}]!=nullptr);

// checking the sniper commadner hitted the foot commander
CHECK(board[{0,3}]->getHealth()==50);
// checking if sniper also hits sniper from team 1
CHECK(board[{0, 1}]->getHealth()==50);





}

TEST_CASE ("checking has_soldiers function") {

Board board(4, 4);

    board[{0, 1}] = new Paramedic(1);


    board[{3, 1}] = new SniperCommander(2);

// moving sniper and checking if moved
board.move(2, {3, 1}, WarGame::Board::Right);
CHECK(board[{3,1}]==nullptr);
CHECK(board[{3,2}]!=nullptr);

CHECK(board.has_soldiers(1)==false);
CHECK(board[{0,1}]==nullptr);



}


TEST_CASE ("Moving tests") {
    Board board(8, 8);


    board[{0, 1}] = new FootSoldier(1);
    board[{0, 3}] = new FootCommander(1);
    board[{0, 5}] = new FootSoldier(1);
   board[{1, 5}] = new Sniper(1);
    board[{1, 2}] = new Paramedic(1);

    board[{7, 1}] = new Sniper(2);
    board[{7, 3}] = new FootCommander(2);
    board[{7, 5}] = new FootSoldier(2);
    board[{6, 2}] = new SniperCommander(2);
    board[{6, 5}] = new Sniper(2);

            CHECK(typeid(board[{0, 1}]) == typeid(Soldier*));

    board.move(1, {0, 1}, WarGame::Board::Up);
          CHECK(board[{1,1}]!= nullptr);
            CHECK(board[{6,2}]->getHealth()==110);
            board.move(2,{6,5},WarGame::Board::Down);
            CHECK(board[{5,5}]!= nullptr);
            CHECK(board[{0,3}]->getHealth()==100);
	CHECK_THROWS(board.move(1, {0, 3}, WarGame::Board::Down));
	CHECK_THROWS(board.move(1, {7, 3}, WarGame::Board::Up));
	board.move(2, {5, 5}, WarGame::Board::Right);
	board.move(2, {5, 6}, WarGame::Board::Right);
	CHECK_THROWS(board.move(2, {5, 7}, WarGame::Board::Right));	board.move(2, {7, 1}, WarGame::Board::Right);
CHECK_THROWS(board.move(2, {7, 2}, WarGame::Board::Right));
 board.move(2,{6,2},WarGame::Board::Down);
// paramedic is dead now
 CHECK(board[{1,2}]==nullptr);
// FootSoldier of team 1 is also dead	
CHECK(board[{0,1}]==nullptr);
// attack with sniper of team 1
board.move(1, {1, 5}, WarGame::Board::Left);
 CHECK(board[{7,3}]->getHealth()==100);
CHECK(board[{1,4}]!=nullptr);	




}

TEST_CASE ("Healing tests") {

Board board(4, 4);

    board[{0, 1}] = new FootSoldier(1);
    board[{0, 3}] = new FootCommander(1);
    board[{1, 2}] = new Paramedic(1);

    board[{3, 1}] = new Sniper(2);
    board[{3, 3}] = new FootCommander(2);
    board[{3, 2}] = new FootSoldier(2);

// moving sniper and hitting the foot commander of team 1	
board.move(2, {3, 1}, WarGame::Board::Down);
// check if the foot commander is hit
  CHECK(board[{0,3}]->getHealth()==100);

// moving right with the healer and check if heals the foot commander
board.move(1, {1, 2}, WarGame::Board::Right);
CHECK(board[{0,3}]->getHealth()==150);

}

TEST_CASE ("Test ilegal moves : ") {

	Board board(8,8);
	//Player1
 	board[{0, 1}] = new Sniper(1);
 	board[{0, 2}] = new FootSoldier(1);
        board[{0, 3}] = new ParamedicCommander(1);
        board[{0, 4}] = new FootCommander(1);
        board[{0, 5}] = new FootSoldier(1);
        board[{0, 6}] = new Paramedic(1);

        //Player2
        board[{7, 1}] = new FootCommander(2);
 	board[{7, 2}] = new Sniper(2);
 	board[{7, 3}] = new Paramedic(2);
        board[{7, 4}] = new FootCommander(2);
        board[{7, 5}] = new FootSoldier(2);
 	board[{7, 6}] = new SniperCommander(2);


	// Checking ilegal moves Player 1 : 
            CHECK_THROWS( board.move(1, {0, 1}, Board::MoveDIR::Down));
            CHECK_THROWS( board.move(1, {0, 1}, Board::MoveDIR::Right));
            CHECK_THROWS( board.move(1, {0, 2}, Board::MoveDIR::Right));
            CHECK_THROWS( board.move(1, {0, 2}, Board::MoveDIR::Down));
            CHECK_THROWS(  board.move(1, {0, 3}, Board::MoveDIR::Left));
  	    CHECK_THROWS(  board.move(1, {0, 4}, Board::MoveDIR::Right));
            CHECK_THROWS(  board.move(1, {0, 5}, Board::MoveDIR::Down));

	// Checking ilegal moves Player 2 : 
            CHECK_THROWS( board.move(2, {7, 1}, Board::MoveDIR::Up));
            CHECK_THROWS( board.move(2, {7, 1}, Board::MoveDIR::Right));
            CHECK_THROWS( board.move(2, {7, 2}, Board::MoveDIR::Left));
            CHECK_THROWS( board.move(2, {7, 2}, Board::MoveDIR::Right));
            CHECK_THROWS(  board.move(2, {7, 3}, Board::MoveDIR::Right));
            CHECK_THROWS( board.move(2, {7, 4}, Board::MoveDIR::Left));
            CHECK_THROWS(  board.move(2, {7, 5}, Board::MoveDIR::Up));
}
TEST_CASE ("Test damage :") {

	Board board(8,8);
	//Player1
 	board[{0, 1}] = new Sniper(1);
 	board[{0, 2}] = new FootSoldier(1);
        board[{0, 3}] = new ParamedicCommander(1);
        board[{0, 4}] = new FootCommander(1);
        board[{0, 5}] = new FootSoldier(1);
        board[{0, 6}] = new Paramedic(1);

        //Player2
        board[{7, 1}] = new FootCommander(2);
 	board[{7, 2}] = new Paramedic(2);
 	board[{7, 3}] = new FootSoldier(2);
        board[{7, 4}] = new FootSoldier(2);
        board[{7, 5}] = new Paramedic(2);
 	board[{7, 6}] = new SniperCommander(2);

	//player 1:
	board.move(1, {0, 1}, Board::MoveDIR::Up);
	CHECK(board.getBoard()[7][1]->getHealth()==100);
	board.move(1, {1, 1}, Board::MoveDIR::Up);
	CHECK(board.getBoard()[7][6]->getHealth()==70);

	//player 2:
	board.move(2, {7, 6}, Board::MoveDIR::Down);
	CHECK(board.getBoard()[0][3]->getHealth()==100);
	board.move(2, {6, 6}, Board::MoveDIR::Down);
	CHECK(board.getBoard()[0][4]->getHealth()==50);
}

TEST_CASE ("Small board test 1: ") {

	Board board(4,4);
	//Player1
        board[{0, 1}] = new FootSoldier(1);
 	board[{0, 2}] = new Paramedic(1);
 	board[{0, 3}] = new FootSoldier(1);

        //Player2
        board[{3, 0}] = new FootSoldier(2);
 	board[{3, 1}] = new Paramedic(2);
 	board[{2, 0}] = new FootSoldier(2);



	// Checking ilegal moves Player 1 : 
            CHECK_THROWS( board.move(1, {0, 1}, Board::MoveDIR::Down));
            CHECK_THROWS( board.move(1, {0, 1}, Board::MoveDIR::Right));
            CHECK_THROWS( board.move(1, {0, 2}, Board::MoveDIR::Down));
 	    CHECK_THROWS( board.move(1, {0, 2}, Board::MoveDIR::Down));
            CHECK_THROWS( board.move(1, {0, 2}, Board::MoveDIR::Left));


	// Checking ilegal moves Player 2 : 
            CHECK_THROWS( board.move(2, {3, 0}, Board::MoveDIR::Down));
            CHECK_THROWS( board.move(2, {3, 0}, Board::MoveDIR::Up));
	    CHECK_THROWS( board.move(2, {3, 0}, Board::MoveDIR::Right));
            CHECK_THROWS( board.move(2, {3, 1}, Board::MoveDIR::Left));

	// checking damages and healing after moves :
	board.move(2, {2, 0}, Board::MoveDIR::Down);
	CHECK(board.getBoard()[0][1]->getHealth()==90);
	board.move(1, {0, 2}, Board::MoveDIR::Up);
	CHECK(board.getBoard()[0][1]->getHealth()==100);
	CHECK(board.getBoard()[0][1]->getHealth()==100);

	board.move(1, {0, 3}, Board::MoveDIR::Up);
	CHECK(board.getBoard()[3][1]->getHealth()==90);
	board.move(2, {3, 1}, Board::MoveDIR::Down);
	CHECK(board.getBoard()[1][0]->getHealth()==100);
	CHECK(board.getBoard()[1][0]->getHealth()==100);

}

TEST_CASE ("Small board ilegal moves test 2: ") {

	Board board(2,2);
	//Player1
        board[{0, 0}] = new FootSoldier(1);

        //Player2
        board[{1, 1}] = new Sniper(2);



	// Checking ilegal moves Player 1 : 
            CHECK_THROWS( board.move(1, {0, 0}, Board::MoveDIR::Down));
            CHECK_THROWS( board.move(1, {0, 0}, Board::MoveDIR::Down));
            CHECK_THROWS( board.move(1, {0, 0}, Board::MoveDIR::Left));
            CHECK_THROWS( board.move(1, {0, 0}, Board::MoveDIR::Left));


	// Checking ilegal moves Player 2 : 
            CHECK_THROWS( board.move(2, {1, 1}, Board::MoveDIR::Up));
CHECK_THROWS( board.move(2, {1, 1}, Board::MoveDIR::Up));
	    CHECK_THROWS( board.move(2, {1, 1}, Board::MoveDIR::Right));
  CHECK_THROWS( board.move(2, {1, 1}, Board::MoveDIR::Right));

}
TEST_CASE ("has_soldier function test case") {

	Board board(2,2);
	//Player1
        board[{0, 0}] = new FootSoldier(1);

        //Player2
        board[{1, 1}] = new SniperCommander(2);



	// Checking ilegal moves Player 1 : 
            CHECK_THROWS( board.move(1, {0, 0}, Board::MoveDIR::Down));
            CHECK_THROWS( board.move(1, {0, 0}, Board::MoveDIR::Left));


	// Checking ilegal moves Player 2 : 
            CHECK_THROWS( board.move(2, {1, 1}, Board::MoveDIR::Up));
	    CHECK_THROWS( board.move(2, {1, 1}, Board::MoveDIR::Right));



	Board board1(8,8);
	//Player1
 	board1[{0, 1}] = new Sniper(1);
 	board1[{0, 2}] = new FootSoldier(1);
        board1[{0, 3}] = new ParamedicCommander(1);
        board1[{0, 4}] = new FootCommander(1);
        board1[{0, 5}] = new FootSoldier(1);
        board1[{0, 6}] = new Paramedic(1);

        //Player2
        board1[{7, 1}] = new FootCommander(2);
 	board1[{7, 2}] = new Paramedic(2);
 	board1[{7, 3}] = new FootSoldier(2);
        board1[{7, 4}] = new FootSoldier(2);
        board1[{7, 5}] = new Paramedic(2);
 	board1[{7, 6}] = new SniperCommander(2);

	//player 1:
	board1.move(1, {0, 1}, Board::MoveDIR::Up);
	CHECK(board1.getBoard()[7][1]->getHealth()==100);
	board1.move(1, {1, 1}, Board::MoveDIR::Up);
	CHECK(board1.getBoard()[7][6]->getHealth()==70);

	//player 2:
	board1.move(2, {7, 6}, Board::MoveDIR::Down);
	CHECK(board1.getBoard()[0][3]->getHealth()==100);
	board1.move(2, {6, 6}, Board::MoveDIR::Down);
	CHECK(board1.getBoard()[0][4]->getHealth()==50);

}
TEST_CASE ("Test: ") {

	Board board(8,8);
	//Player1
 	board[{0, 1}] = new Sniper(1);
 	board[{0, 2}] = new FootSoldier(1);
        board[{0, 3}] = new ParamedicCommander(1);
        board[{0, 4}] = new FootCommander(1);
        board[{0, 5}] = new FootSoldier(1);
        board[{0, 6}] = new Paramedic(1);

        //Player2
        board[{7, 1}] = new FootCommander(2);
 	board[{7, 2}] = new Sniper(2);
 	board[{7, 3}] = new Paramedic(2);
        board[{7, 4}] = new FootCommander(2);
        board[{7, 5}] = new FootSoldier(2);
 	board[{7, 6}] = new SniperCommander(2);


	// Checking ilegal moves Player 1 : 
            CHECK_THROWS( board.move(1, {0, 1}, Board::MoveDIR::Down));
            CHECK_THROWS( board.move(1, {0, 1}, Board::MoveDIR::Right));
            CHECK_THROWS( board.move(1, {0, 2}, Board::MoveDIR::Right));
            CHECK_THROWS( board.move(1, {0, 2}, Board::MoveDIR::Down));
            CHECK_THROWS(  board.move(1, {0, 3}, Board::MoveDIR::Left));
  	    CHECK_THROWS(  board.move(1, {0, 4}, Board::MoveDIR::Right));
            CHECK_THROWS(  board.move(1, {0, 5}, Board::MoveDIR::Down));

	// Checking ilegal moves Player 2 : 
            CHECK_THROWS( board.move(2, {7, 1}, Board::MoveDIR::Up));
            CHECK_THROWS( board.move(2, {7, 1}, Board::MoveDIR::Right));
            CHECK_THROWS( board.move(2, {7, 2}, Board::MoveDIR::Left));
            CHECK_THROWS( board.move(2, {7, 2}, Board::MoveDIR::Right));
            CHECK_THROWS(  board.move(2, {7, 3}, Board::MoveDIR::Right));
            CHECK_THROWS( board.move(2, {7, 4}, Board::MoveDIR::Left));
            CHECK_THROWS(  board.move(2, {7, 5}, Board::MoveDIR::Up));
}
