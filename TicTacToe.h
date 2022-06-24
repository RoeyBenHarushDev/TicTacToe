#pragma once 
#include <iostream>
#include "boardGame.h"

class TicTacToe: public BoardGame {

    public:
    TicTacToe():BoardGame(3,3){}
    bool is_Valid_move (Move& m) const;
    void set_player_move(Move& m);
    bool is_Game_End();


    private:
    bool X_won_Row() const; 
    bool O_won_Row() const;

    bool X_won_col() const;
    bool O_won_col() const;

    bool X_won_slant()const;
    bool O_won_slant()const;

    bool Is_Game_End_Tie ()const;

};