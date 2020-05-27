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

}
