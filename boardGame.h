#pragma once 
#include <iostream>
#include <vector>
#include <memory.h>
#include "game.h"


using namespace std;

class BoardGame : public Game {

    public:
    BoardGame(int col=0, int row=0): Game(){
        m_col = col;
        m_row = row;
        m_board.resize(m_row, vector<char>(m_col,'-'));
    }

    void showGame(UI showGameOption)const {
        if(showGameOption==Console){
        for (auto &row : m_board )
        {
            for (auto &s : row ) 
            {cout << s << ' ';}
            cout << endl;
        }
        }
        else if(showGameOption==Graphical){
            cout<<"This option is not available right now"<<endl;
        } 
    }

    GameState get_game_state() const {
        return m_state;
    }

    void print_Game_End(UI showGameOption) const{

        if(showGameOption==Console){
        if (get_game_state() == PlayerWins)
                cout << "Player You Win !! :) " << endl;

            else if (get_game_state() == ComuterWins)
                cout << "Player You are looser !! :( " << endl;

            else if (get_game_state() == Tie)
                cout << "It's a tie :O " << endl;
            
            showGame(Console);
            cout<<endl;
        }

        else if(showGameOption==Graphical){
            cout<<"This option is not available right now"<<endl;
        }
    }

    Move& try_move(){
            int row, col;
            char comma;

            cout <<endl<< "Enter position Row,Col:  ";
            cin >> row;
            cin >> comma;
            cin >> col;
            m_move.set_x(row-1);
            m_move.set_y(col-1);

            return m_move;
    }


    protected:
    vector<vector<char>> m_board;    
    int m_col;
    int m_row;

};