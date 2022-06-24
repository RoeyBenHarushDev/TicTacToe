#pragma once 
#include <iostream>
#include "TicTacToe.h"

class TicTacToeHighLevel : public TicTacToe {

    public:
    TicTacToeHighLevel(): TicTacToe(){}
    void set_computer_move();
        
    private:
    void Set_O();
    bool check_Rows(char temp);
    bool check_Cols(char temp);
    bool check_Slants(char temp);

};
