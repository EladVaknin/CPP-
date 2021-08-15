
/**
 * @file Test.cpp
 * @author Elad Vaknin
 * @brief tests for the second assignment messageboard
 * @date 2021-03-24
 * @copyright Copyright (c) 2021
 * 
 */

#include <string>
#include "doctest.h"
#include "Direction.hpp"
#include "Board.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Board changes") {
    Board board;
    CHECK_NOTHROW(board.post(4,5,Direction::Horizontal,"Elad"));
    CHECK_NOTHROW(board.post(4,5,Direction::Vertical,"Elad"));
    CHECK(board.read(4,5,Direction::Horizontal,4) == "Elad");
    CHECK(board.read(4,5,Direction::Vertical,4) == "Elad");
    CHECK_NOTHROW(board.post(4,5,Direction::Horizontal,"A"));
    CHECK(board.read(4,5,Direction::Horizontal,5) == "Alad");
    CHECK(board.read(4,5,Direction::Vertical,5) == "Alad");
    CHECK_NOTHROW(board.post(4,6,Direction::Horizontal,"B"));
    CHECK(board.read(4,5,Direction::Horizontal,5) == "Blad");
    CHECK(board.read(4,5,Direction::Vertical,5) == "Blad");
    CHECK_NOTHROW(board.post(4,5,Direction::Horizontal,"Pizza"));
    CHECK_NOTHROW(board.post(4,5,Direction::Vertical,"Pizza"));
    CHECK(board.read(4,5,Direction::Horizontal,8) == "Pizza");
    CHECK(board.read(4,5,Direction::Vertical,8) == "Pizza");
}

TEST_CASE("Exceptions Error") {
    Board board;
    CHECK_THROWS(board.read(0,0,Direction::Horizontal,7));
    CHECK_THROWS(board.read(0,0,Direction::Vertical,8));
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"Elad"));
    CHECK_NOTHROW(board.post(0,0,Direction::Vertical,"Vaknin"));
    CHECK_THROWS(board.read(450,450,Direction::Horizontal,6));
    CHECK_THROWS(board.read(450,450,Direction::Vertical,17));
    CHECK_NOTHROW(board.post(450,450,Direction::Horizontal,"Vaknin"));
    CHECK_NOTHROW(board.post(450,450,Direction::Vertical,"Vaknin"));
    CHECK_NOTHROW(board.read(450,450,Direction::Horizontal,6));
    CHECK_NOTHROW(board.read(450,450,Direction::Vertical,6));
}



