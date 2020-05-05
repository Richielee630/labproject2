#include "gtest/gtest.h"
#include <vector>

bool valid_board(std::vector<char> board){
    if(board.size() != 9) return false;
    int o = 0;
    int x = 0;
    int invalid = 0;
    for(char location: board){
        switch(location) {
            case ('O'):
                o++;
                break;
            case ('X'):
                x++;
                break;
            case ('\0'):
                break;
            default:
                invalid++;
                break;
        }
    }
    if(o-x > 1 || o-x < -1 || invalid > 0) return false;
    return true;
}

/*
 *  [0] [1] [2]
 *  [3] [4] [5]
 *  [6] [7] [8]
 *  Win occurs when either X or O is in every space on a row or column or diagonal.
 */

char score_board(std::vector<char> board){
    if(valid_board(board)){
        //Check rows, third comparison isn't needed, but is safe
        if(board[0] == board[1] && board[0] == board[2] && board[1] == board[2] && board[0] != '\0') return board[0];
        else if(board[3] == board[4] && board[3] == board[5] && board[4] == board[5] && board[3] != '\0') return board[3];
        else if(board[6] == board[7] && board[6] == board[8] && board[7] == board[8] && board[6] != '\0') return board[6];

        //Check columns
        else if(board[0] == board[3] && board[0] == board[6] && board[3] == board[6] && board[0] != '\0') return board[0];
        else if(board[1] == board[4] && board[1] == board[7] && board[4] == board[7] && board[1] != '\0') return board[1];
        else if(board[2] == board[5] && board[2] == board[8] && board[5] == board[8] && board[2] != '\0') return board[2];

        //Check Diagonal
        else if(board[0] == board[4] && board[0] == board[8] && board[4] == board[8] && board[4] != '\0') return board[4];
        else if(board[2] == board[4] && board[2] == board[6] && board[4] == board[6] && board[4] != '\0') return board[4];

        //Check for draw
        else{
            int count = 0;
            for(char item: board) if(item != '\0') count++;
            if(count == 9) return 'D';
        }

        //If nothing won, return null char;
        return '\0';
    }
    else return 'e';
}

// You write this test case.
TEST(Part1, Test1){
    EXPECT_TRUE(true);
}

// You write this test case.
TEST(Part1, Test2){
    EXPECT_TRUE(true);
}

// You write this test case.
TEST(Part1, Test3){
    EXPECT_TRUE(true);
}