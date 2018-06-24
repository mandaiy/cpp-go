#include <gtest/gtest.h>

#include "move.hpp"
#include "state.hpp"

using namespace cppgo;


TEST(state_test, real_game_1) {
    State s(9, 7.5, false, 0);

    auto moves = {
            Move::from_gtp_string("D5", 9),
            Move::from_gtp_string("C3", 9),
            Move::from_gtp_string("E7", 9),
            Move::from_gtp_string("F3", 9),
            Move::from_gtp_string("G5", 9),
            Move::from_gtp_string("E4", 9),
            Move::from_gtp_string("C4", 9),
            Move::from_gtp_string("B3", 9),
            Move::from_gtp_string("G3", 9),
            Move::from_gtp_string("G4", 9),
            Move::from_gtp_string("H4", 9),
            Move::from_gtp_string("F4", 9),
            Move::from_gtp_string("H2", 9),
            Move::from_gtp_string("G2", 9),
            Move::from_gtp_string("H3", 9),
            Move::from_gtp_string("F6", 9),
            Move::from_gtp_string("F5", 9),
            Move::from_gtp_string("E5", 9),
            Move::from_gtp_string("E6", 9),
            Move::from_gtp_string("F7", 9),
            Move::from_gtp_string("G6", 9),
            Move::from_gtp_string("E8", 9),
            Move::from_gtp_string("D8", 9),
            Move::from_gtp_string("C9", 9),
            Move::from_gtp_string("F8", 9),
            Move::from_gtp_string("D6", 9),
            Move::from_gtp_string("D7", 9),
            Move::from_gtp_string("C6", 9),
            Move::from_gtp_string("C7", 9),
            Move::from_gtp_string("B6", 9),
            Move::from_gtp_string("B7", 9),
            Move::from_gtp_string("A7", 9),
            Move::from_gtp_string("B5", 9),
            Move::from_gtp_string("G7", 9),
            Move::from_gtp_string("C5", 9),
            Move::from_gtp_string("H7", 9),
            Move::from_gtp_string("H6", 9),
            Move::from_gtp_string("G8", 9),
            Move::from_gtp_string("E9", 9),
            Move::from_gtp_string("F2", 9),
            Move::from_gtp_string("J5", 9),
            Move::from_gtp_string("J6", 9),
            Move::from_gtp_string("J7", 9),
            Move::from_gtp_string("J8", 9),
            Move::from_gtp_string("H9", 9),
            Move::from_gtp_string("J6", 9),
            Move::from_gtp_string("H5", 9),
            Move::from_gtp_string("G9", 9),
            Move::from_gtp_string("H1", 9),
            Move::from_gtp_string("J2", 9),
            Move::from_gtp_string("J3", 9),
            Move::from_gtp_string("F9", 9),
            Move::from_gtp_string("E8", 9),
            Move::from_gtp_string("A6", 9),
            Move::from_gtp_string("A5", 9),
            Move::from_gtp_string("A8", 9),
            Move::from_gtp_string("B8", 9),
            Move::from_gtp_string("B4", 9),
            Move::from_gtp_string("A9", 9),
            Move::from_gtp_string("D4", 9),
            Move::from_gtp_string("A4", 9),
            Move::from_gtp_string("D6", 9),
            Move::from_gtp_string("A3", 9),
            Move::from_gtp_string("B2", 9),
            Move::from_gtp_string("A2", 9),
            Move::from_gtp_string("A1", 9),
            Move::from_gtp_string("E3", 9),
            Move::from_gtp_string("G1", 9),
            Move::from_gtp_string("D2", 9),
            Move::from_gtp_string("D3", 9),
            Move::from_gtp_string("J7", 9),
            Move::from_gtp_string("B1", 9),
            Move::from_gtp_string("H8", 9),
            Move::from_gtp_string("B6", 9),
            Move::from_gtp_string("C6", 9),
            Move::from_gtp_string("E2", 9),
            Move::from_gtp_string("A6", 9),
            Move::from_gtp_string("H7", 9),
            Move::from_gtp_string("G7", 9),
            Move::from_gtp_string("A8", 9),
            Move::from_gtp_string("A7", 9),
            Move::from_gtp_string("B9", 9),
            Move::from_gtp_string("J9", 9),
            Move::from_gtp_string("A8", 9),
            Move::from_gtp_string("J1", 9),
            Move::from_gtp_string("A9", 9),
            Move::from_gtp_string("C8", 9),
            Move::from_gtp_string("D1", 9),
            Move::from_gtp_string("D9", 9),
            Move::from_gtp_string("C2", 9),
            Move::from_gtp_string("E1", 9),
            Move::from_gtp_string("F1", 9),
            Move::from_gtp_string("F6", 9),
            Move::from_gtp_string("G9", 9),
            Move::from_gtp_string("F9", 9),
            Move::from_gtp_string("C9", 9),
            Move::from_gtp_string("B9", 9),
            Move::from_gtp_string("A9", 9),
            Move::from_gtp_string("A8", 9),
            Move::from_gtp_string("PASS", 9),
            Move::from_gtp_string("G8", 9),
            Move::from_gtp_string("PASS", 9),
            Move::from_gtp_string("PASS", 9)
    };

    /*
         A  B  C  D  E  F  G  H  J
       9 .  X  .  X  X  X  .  X  X 9
       8 X  X  X  X  X  X  X  X  . 8
       7 X  X  X  X  X  .  X  .  X 7
       6 X  .  X  .  X  X  X  X  . 6
       5 X  X  X  X  O  X  X  X  X 5
       4 X  O  X  O  O  O  O  X  . 4
       3 X  O  O  O  .  O  X  X  X 3
       2 X  O  O  .  O  O  O  X  . 2
       1 O  O  .  O  .  O  O  X  X 1
         A  B  C  D  E  F  G  H  J
    */

    for (auto m : moves) {
        s.make_move(m);
    }

    std::vector<int> black_board = {
            0, 0, 0, 0, 0, 0, 0, 1, 1,
            1, 0, 0, 0, 0, 0, 0, 1, 0,
            1, 0, 0, 0, 0, 0, 1, 1, 1,
            1, 0, 1, 0, 0, 0, 0, 1, 0,
            1, 1, 1, 1, 0, 1, 1, 1, 1,
            1, 0, 1, 0, 1, 1, 1, 1, 0,
            1, 1, 1, 1, 1, 0, 1, 0, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 0,
            0, 1, 0, 1, 1, 1, 0, 1, 1,
    };

    std::vector<int> white_board = {
            1, 1, 0, 1, 0, 1, 1, 0, 0,
            0, 1, 1, 0, 1, 1, 1, 0, 0,
            0, 1, 1, 1, 0, 1, 0, 0, 0,
            0, 1, 0, 1, 1, 1, 1, 0, 0,
            0, 0, 0, 0, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    ASSERT_EQ(black_board, s.black_board());
    ASSERT_EQ(white_board, s.white_board());
}


TEST(state_test, real_game_2) {
    State s(9, 7.5, false, 0);

    auto moves = {
            Move::from_gtp_string("F6", 9),
            Move::from_gtp_string("D7", 9),
            Move::from_gtp_string("E7", 9),
            Move::from_gtp_string("D6", 9),
            Move::from_gtp_string("F4", 9),
            Move::from_gtp_string("D4", 9),
            Move::from_gtp_string("D3", 9),
            Move::from_gtp_string("C3", 9),
            Move::from_gtp_string("E3", 9),
            Move::from_gtp_string("G5", 9),
            Move::from_gtp_string("G6", 9),
            Move::from_gtp_string("F5", 9),
            Move::from_gtp_string("E5", 9),
            Move::from_gtp_string("E4", 9),
            Move::from_gtp_string("G4", 9),
            Move::from_gtp_string("H5", 9),
            Move::from_gtp_string("D5", 9),
            Move::from_gtp_string("C4", 9),
            Move::from_gtp_string("E6", 9),
            Move::from_gtp_string("C5", 9),
            Move::from_gtp_string("H4", 9),
            Move::from_gtp_string("F3", 9),
            Move::from_gtp_string("F2", 9),
            Move::from_gtp_string("E8", 9),
            Move::from_gtp_string("F8", 9),
            Move::from_gtp_string("D8", 9),
            Move::from_gtp_string("C2", 9),
            Move::from_gtp_string("H6", 9),
            Move::from_gtp_string("G7", 9),
            Move::from_gtp_string("B2", 9),
            Move::from_gtp_string("C6", 9),
            Move::from_gtp_string("H8", 9),
            Move::from_gtp_string("G8", 9),
            Move::from_gtp_string("C7", 9),
            Move::from_gtp_string("B6", 9),
            Move::from_gtp_string("H7", 9),
            Move::from_gtp_string("H9", 9),
            Move::from_gtp_string("E9", 9),
            Move::from_gtp_string("J5", 9),
            Move::from_gtp_string("D2", 9),
            Move::from_gtp_string("E2", 9),
            Move::from_gtp_string("F9", 9),
            Move::from_gtp_string("G9", 9),
            Move::from_gtp_string("C1", 9),
            Move::from_gtp_string("J6", 9),
            Move::from_gtp_string("B7", 9),
            Move::from_gtp_string("G3", 9),
            Move::from_gtp_string("E1", 9),
            Move::from_gtp_string("F1", 9),
            Move::from_gtp_string("D1", 9),
            Move::from_gtp_string("J8", 9),
            Move::from_gtp_string("G2", 9),
            Move::from_gtp_string("J7", 9),
            Move::from_gtp_string("G1", 9),
            Move::from_gtp_string("F3", 9),
            Move::from_gtp_string("H2", 9),
            Move::from_gtp_string("H3", 9),
            Move::from_gtp_string("J3", 9),
            Move::from_gtp_string("J4", 9),
            Move::from_gtp_string("J1", 9),
            Move::from_gtp_string("J2", 9),
            Move::from_gtp_string("G5", 9),
            Move::from_gtp_string("H1", 9),
            Move::from_gtp_string("B5", 9),
            Move::from_gtp_string("B1", 9),
            Move::from_gtp_string("A1", 9),
            Move::from_gtp_string("A2", 9),
            Move::from_gtp_string("A3", 9),
            Move::from_gtp_string("B3", 9),
            Move::from_gtp_string("A6", 9),
            Move::from_gtp_string("A4", 9),
            Move::from_gtp_string("B4", 9),
            Move::from_gtp_string("J9", 9),
            Move::from_gtp_string("A5", 9),
            Move::from_gtp_string("J1", 9),
            Move::from_gtp_string("D9", 9),
            Move::from_gtp_string("B8", 9),
            Move::from_gtp_string("B9", 9),
            Move::from_gtp_string("A8", 9),
            Move::from_gtp_string("A7", 9),
            Move::from_gtp_string("C8", 9),
            Move::from_gtp_string("C9", 9),
            Move::from_gtp_string("C6", 9),
            Move::from_gtp_string("A9", 9),
            Move::from_gtp_string("B8", 9),
            Move::from_gtp_string("A8", 9),
            Move::from_gtp_string("H5", 9),
            Move::from_gtp_string("H7", 9),
            Move::from_gtp_string("H6", 9),
            Move::from_gtp_string("G2", 9),
            Move::from_gtp_string("G1", 9),
            Move::from_gtp_string("A2", 9),
            Move::from_gtp_string("H2", 9),
            Move::from_gtp_string("B6", 9),
            Move::from_gtp_string("F5", 9),
            Move::from_gtp_string("C8", 9),
            Move::from_gtp_string("H8", 9),
            Move::from_gtp_string("PASS", 9),
            Move::from_gtp_string("PASS", 9),
    };

    for (auto const &m : moves) {
        s.make_move(m);
    }

    /*
        A  B  C  D  E  F  G  H  J
      9 O  O  O  O  O  O  X  X  X 9
      8 O  .  O  O  O  X  X  X  X 8
      7 O  O  O  O  X  .  X  .  X 7
      6 O  O  .  O  X  X  X  X  X 6
      5 O  O  O  X  X  X  .  X  X 5
      4 .  O  O  O  O  X  X  X  X 4
      3 O  .  O  X  X  X  X  X  . 3
      2 O  O  .  O  X  X  .  X  X 2
      1 O  .  O  O  O  X  X  X  X 1
        A  B  C  D  E  F  G  H  J
    */

    std::vector<int> black_board = {
            0, 0, 0, 0, 0, 1, 1, 1, 1,
            0, 0, 0, 0, 1, 1, 0, 1, 1,
            0, 0, 0, 1, 1, 1, 1, 1, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1,
            0, 0, 0, 1, 1, 1, 0, 1, 1,
            0, 0, 0, 0, 1, 1, 1, 1, 1,
            0, 0, 0, 0, 1, 0, 1, 0, 1,
            0, 0, 0, 0, 0, 1, 1, 1, 1,
            0, 0, 0, 0, 0, 0, 1, 1, 1,
    };

    std::vector<int> white_board = {
            1, 0, 1, 1, 1, 0, 0, 0, 0,
            1, 1, 0, 1, 0, 0, 0, 0, 0,
            1, 0, 1, 0, 0, 0, 0, 0, 0,
            0, 1, 1, 1, 1, 0, 0, 0, 0,
            1, 1, 1, 0, 0, 0, 0, 0, 0,
            1, 1, 0, 1, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 0, 0, 0, 0, 0,
            1, 0, 1, 1, 1, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1, 0, 0, 0,
    };

    ASSERT_EQ(black_board, s.black_board());
    ASSERT_EQ(white_board, s.white_board());
}

TEST(state_test, real_game_3) {

    auto moves = {
            Move::from_gtp_string("D4", 9),
            Move::from_gtp_string("E7", 9),
            Move::from_gtp_string("G6", 9),
            Move::from_gtp_string("E5", 9),
            Move::from_gtp_string("D5", 9),
            Move::from_gtp_string("E4", 9),
            Move::from_gtp_string("E6", 9),
            Move::from_gtp_string("F6", 9),
            Move::from_gtp_string("D6", 9),
            Move::from_gtp_string("F7", 9),
            Move::from_gtp_string("F5", 9),
            Move::from_gtp_string("E3", 9),
            Move::from_gtp_string("G4", 9),
            Move::from_gtp_string("G7", 9),
            Move::from_gtp_string("D3", 9),
            Move::from_gtp_string("D2", 9),
            Move::from_gtp_string("C2", 9),
            Move::from_gtp_string("G2", 9),
            Move::from_gtp_string("H3", 9),
            Move::from_gtp_string("E2", 9),
            Move::from_gtp_string("H6", 9),
            Move::from_gtp_string("D7", 9),
            Move::from_gtp_string("C7", 9),
            Move::from_gtp_string("C3", 9),
            Move::from_gtp_string("B3", 9),
            Move::from_gtp_string("F4", 9),
            Move::from_gtp_string("G5", 9),
            Move::from_gtp_string("H2", 9),
            Move::from_gtp_string("H7", 9),
            Move::from_gtp_string("C8", 9),
            Move::from_gtp_string("B7", 9),
            Move::from_gtp_string("H8", 9),
            Move::from_gtp_string("J8", 9),
            Move::from_gtp_string("H9", 9),
            Move::from_gtp_string("B8", 9),
            Move::from_gtp_string("D9", 9),
            Move::from_gtp_string("J5", 9),
            Move::from_gtp_string("J7", 9),
            Move::from_gtp_string("J2", 9),
            Move::from_gtp_string("G3", 9),
            Move::from_gtp_string("J3", 9),
            Move::from_gtp_string("H4", 9),
            Move::from_gtp_string("D1", 9),
            Move::from_gtp_string("E1", 9),
            Move::from_gtp_string("F2", 9),
            Move::from_gtp_string("B2", 9),
            Move::from_gtp_string("C4", 9),
            Move::from_gtp_string("C1", 9),
            Move::from_gtp_string("H1", 9),
            Move::from_gtp_string("C3", 9),
            Move::from_gtp_string("G1", 9),
            Move::from_gtp_string("B4", 9),
            Move::from_gtp_string("C2", 9),
            Move::from_gtp_string("A3", 9),
            Move::from_gtp_string("F9", 9),
            Move::from_gtp_string("F3", 9),
            Move::from_gtp_string("F8", 9),
            Move::from_gtp_string("C3", 9),
            Move::from_gtp_string("B5", 9),
            Move::from_gtp_string("A5", 9),
            Move::from_gtp_string("C6", 9),
            Move::from_gtp_string("A7", 9),
            Move::from_gtp_string("A8", 9),
            Move::from_gtp_string("E8", 9),
            Move::from_gtp_string("B9", 9),
            Move::from_gtp_string("G8", 9),
            Move::from_gtp_string("E9", 9),
            Move::from_gtp_string("F1", 9),
            Move::from_gtp_string("A6", 9),
            Move::from_gtp_string("J1", 9),
            Move::from_gtp_string("H1", 9),
            Move::from_gtp_string("G1", 9),
            Move::from_gtp_string("J6", 9),
            Move::from_gtp_string("G9", 9),
            Move::from_gtp_string("C9", 9),
            Move::from_gtp_string("F9", 9),
            Move::from_gtp_string("D8", 9),
            Move::from_gtp_string("J1", 9),
            Move::from_gtp_string("E9", 9),
            Move::from_gtp_string("J4", 9),
            Move::from_gtp_string("A4", 9),
            Move::from_gtp_string("B3", 9),
            Move::from_gtp_string("D9", 9),
            Move::from_gtp_string("H5", 9),
            Move::from_gtp_string("A5", 9),
            Move::from_gtp_string("J7", 9),
            Move::from_gtp_string("H7", 9),
            Move::from_gtp_string("H6", 9),
            Move::from_gtp_string("J6", 9),
            Move::from_gtp_string("J5", 9),
            Move::from_gtp_string("B1", 9),
            Move::from_gtp_string("A1", 9),
            Move::from_gtp_string("J2", 9),
            Move::from_gtp_string("H1", 9),
            Move::from_gtp_string("G4", 9),
            Move::from_gtp_string("J9", 9),
            Move::from_gtp_string("F5", 9),
            Move::from_gtp_string("G5", 9),
            Move::from_gtp_string("J3", 9),
            Move::from_gtp_string("H3", 9),
            Move::from_gtp_string("J2", 9),
            Move::from_gtp_string("J3", 9),
            Move::from_gtp_string("PASS", 9),
            Move::from_gtp_string("PASS", 9),
    };

    State s(9, 7.5, false, 0);

    for (auto m : moves) {
        s.make_move(m);
    }

    /*
        A B C D E F G H J
      9 . X X X X O O O O 9
      8 X X . X O . O O . 8
      7 . X X O O O O . O 7
      6 X . X X X O . O . 6
      5 X X . X O . O O O 5
      4 X O X X O O . O O 4
      3 O O O X O O O O O 3
      2 . O . O O . O O . 2
      1 O . O . O O O O O 1
        A B C D E F G H J
     */

    std::vector<int> black_board = {
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 1, 0, 0, 0, 0, 0,
            1, 0, 1, 1, 0, 0, 0, 0, 0,
            1, 1, 0, 1, 0, 0, 0, 0, 0,
            1, 0, 1, 1, 1, 0, 0, 0, 0,
            0, 1, 1, 0, 0, 0, 0, 0, 0,
            1, 1, 0, 1, 0, 0, 0, 0, 0,
            0, 1, 1, 1, 1, 0, 0, 0, 0,
    };

    std::vector<int> white_board = {
            1, 0, 1, 0, 1, 1, 1, 1, 1,
            0, 1, 0, 1, 1, 0, 1, 1, 0,
            1, 1, 1, 0, 1, 1, 1, 1, 1,
            0, 1, 0, 0, 1, 1, 0, 1, 1,
            0, 0, 0, 0, 1, 0, 1, 1, 1,
            0, 0, 0, 0, 0, 1, 0, 1, 0,
            0, 0, 0, 1, 1, 1, 1, 0, 1,
            0, 0, 0, 0, 1, 0, 1, 1, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    ASSERT_EQ(black_board, s.black_board());
    ASSERT_EQ(white_board, s.white_board());
}

TEST(state_test, real_games_4) {
    auto moves = {"Q17", "P6", "F18", "J3", "C4", "O2", "O3", "S8", "N17",
                  "O17", "O18", "C12", "B13", "C13", "C11", "D11", "D12", "B11",
                  "C10", "D10", "B12", "C9", "B10", "B9", "A11", "B18", "C17", "C16",
                  "D13", "C14", "E14", "D14", "D9", "E9", "D8", "E10", "R12", "R11",
                  "S11", "R10", "R8", "R7", "P17", "P18", "R18", "P2", "Q2", "Q3",
                  "P3", "R2", "R3", "Q4", "S2", "Q1", "O1", "Q14", "P14", "B17", "B14",
                  "A15", "B15", "B16", "C15", "D15", "D16", "E15", "F15", "E16", "D17",
                  "Q12", "F16", "O16", "E17", "N18", "M18", "N19", "M17", "M19", "L19",
                  "O19", "L18", "K19", "N16", "P15", "N15", "K18", "O15", "P16", "Q15",
                  "Q16", "R15", "R17", "Q18", "R16", "S17", "S16", "S15", "S14", "T16",
                  "R14", "O18", "O17", "H5", "G5", "N2", "H4", "J12", "S12", "P12", "P11",
                  "P9", "Q8", "P7", "P8", "M4", "N4", "N3", "P4", "F5", "F4", "G6", "E5",
                  "O4", "N5", "P5", "O5", "G4", "G3", "K3", "K2", "J2", "H2", "B2", "B1",
                  "T10", "T8", "Q5", "Q6", "E6", "F6", "G5", "F7", "D7", "D6", "E7", "D5",
                  "F8", "E8", "J7", "J5", "G7", "F7", "G8", "H6", "C3", "B4", "L9",
                  "K10", "J11", "J10", "L10", "K11", "K4", "J4", "J6", "K6", "R5",
                  "R4", "L2", "K1", "G10", "R13", "H15", "G15", "F17", "D15", "K7",
                  "L7", "C5", "B5", "O12", "O11", "O9", "O7", "L6", "K5", "L8", "M7",
                  "K8", "L5", "H7", "H3", "N10", "M11", "N11", "N12", "S3", "S4", "B6",
                  "C6", "B3", "A4", "G16", "H16", "G18", "G14", "M10", "M8", "H11",
    };

    State s(19, 7.5, false, 0);

    for (auto move : moves) {
        s.make_move(Move::from_gtp_string(move, 19));
        std::cout << s.to_string() << std::endl;
    }
}

TEST(state_test, copy) {
    State s(9, 7.5, false, 0);

    auto moves = {
            Move::from_gtp_string("F6", 9),
            Move::from_gtp_string("D7", 9),
            Move::from_gtp_string("E7", 9),
            Move::from_gtp_string("D6", 9),
            Move::from_gtp_string("F4", 9),
            Move::from_gtp_string("D4", 9),
            Move::from_gtp_string("D3", 9),
            Move::from_gtp_string("C3", 9),
            Move::from_gtp_string("E3", 9),
            Move::from_gtp_string("G5", 9),
            Move::from_gtp_string("G6", 9),
            Move::from_gtp_string("F5", 9),
            Move::from_gtp_string("E5", 9),
            Move::from_gtp_string("E4", 9),
            Move::from_gtp_string("G4", 9),
            Move::from_gtp_string("H5", 9),
            Move::from_gtp_string("D5", 9),
            Move::from_gtp_string("C4", 9),
            Move::from_gtp_string("E6", 9),
            Move::from_gtp_string("C5", 9),
            Move::from_gtp_string("H4", 9),
            Move::from_gtp_string("F3", 9),
            Move::from_gtp_string("F2", 9),
            Move::from_gtp_string("E8", 9),
            Move::from_gtp_string("F8", 9),
            Move::from_gtp_string("D8", 9),
            Move::from_gtp_string("C2", 9),
            Move::from_gtp_string("H6", 9),
            Move::from_gtp_string("G7", 9),
            Move::from_gtp_string("B2", 9),
            Move::from_gtp_string("C6", 9),
            Move::from_gtp_string("H8", 9),
            Move::from_gtp_string("G8", 9),
            Move::from_gtp_string("C7", 9),
            Move::from_gtp_string("B6", 9),
            Move::from_gtp_string("H7", 9),
            Move::from_gtp_string("H9", 9),
            Move::from_gtp_string("E9", 9),
            Move::from_gtp_string("J5", 9),
            Move::from_gtp_string("D2", 9),
            Move::from_gtp_string("E2", 9),
            Move::from_gtp_string("F9", 9),
            Move::from_gtp_string("G9", 9),
            Move::from_gtp_string("C1", 9),
            Move::from_gtp_string("J6", 9),
            Move::from_gtp_string("B7", 9),
            Move::from_gtp_string("G3", 9),
            Move::from_gtp_string("E1", 9),
            Move::from_gtp_string("F1", 9),
            Move::from_gtp_string("D1", 9),
            Move::from_gtp_string("J8", 9),
            Move::from_gtp_string("G2", 9),
            Move::from_gtp_string("J7", 9),
            Move::from_gtp_string("G1", 9),
            Move::from_gtp_string("F3", 9),
            Move::from_gtp_string("H2", 9),
            Move::from_gtp_string("H3", 9),
            Move::from_gtp_string("J3", 9),
            Move::from_gtp_string("J4", 9),
            Move::from_gtp_string("J1", 9),
            Move::from_gtp_string("J2", 9),
            Move::from_gtp_string("G5", 9),
            Move::from_gtp_string("H1", 9),
            Move::from_gtp_string("B5", 9),
            Move::from_gtp_string("B1", 9),
            Move::from_gtp_string("A1", 9),
            Move::from_gtp_string("A2", 9),
            Move::from_gtp_string("A3", 9),
            Move::from_gtp_string("B3", 9),
            Move::from_gtp_string("A6", 9),
            Move::from_gtp_string("A4", 9),
            Move::from_gtp_string("B4", 9),
            Move::from_gtp_string("J9", 9),
            Move::from_gtp_string("A5", 9),
            Move::from_gtp_string("J1", 9),
            Move::from_gtp_string("D9", 9),
            Move::from_gtp_string("B8", 9),
            Move::from_gtp_string("B9", 9),
            Move::from_gtp_string("A8", 9),
            Move::from_gtp_string("A7", 9),
            Move::from_gtp_string("C8", 9),
            Move::from_gtp_string("C9", 9),
            Move::from_gtp_string("C6", 9),
            Move::from_gtp_string("A9", 9),
            Move::from_gtp_string("B8", 9),
            Move::from_gtp_string("A8", 9),
            Move::from_gtp_string("H5", 9),
            Move::from_gtp_string("H7", 9),
            Move::from_gtp_string("H6", 9),
            Move::from_gtp_string("G2", 9),
            Move::from_gtp_string("G1", 9),
            Move::from_gtp_string("A2", 9),
            Move::from_gtp_string("H2", 9),
            Move::from_gtp_string("B6", 9),
            Move::from_gtp_string("F5", 9),
            Move::from_gtp_string("C8", 9),
            Move::from_gtp_string("H8", 9),
            Move::from_gtp_string("PASS", 9),
            Move::from_gtp_string("PASS", 9),
    };

    for (auto const &m : moves) {
        s.make_move(m);
    }

    for (int i = 0; i < (1 << 20); ++i) {
        State copy(s);
        copy.komi = s.komi;

        ASSERT_EQ(7.5, copy.komi);
    }

}