#pragma once 
#include <iostream>
#include "move.h"

enum GameState {PlayerWins , ComuterWins, Tie, InProgress};
enum UI{Console=1,Graphical};

class Game {
    public:

    Game(){}
    virtual void set_player_move(Move& m) = 0;
    virtual void set_computer_move() =0;

    virtual GameState get_game_state() const = 0;
    virtual bool is_Valid_move(Move& m) const = 0;
    virtual void showGame(UI showGameOption)const =0;
    virtual void print_Game_End(UI showGameOption) const = 0;
    virtual Move& try_move()=0;

    virtual bool is_Game_End()=0 ;

    protected:
    Move m_move;
    GameState m_state;
};