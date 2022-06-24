#pragma once
#include <iostream>
#include "TicTacToeHighLevel.h"
#include "TicTacToeLowLevel.h"
#include <memory>

// enum Turn {PlayerTurn, ComputerTurn};

using namespace std;
class GameController {

    public:
    void play();

    private:
    std::shared_ptr<Game> curr_Game;
};
