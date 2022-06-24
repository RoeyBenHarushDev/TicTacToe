#include "GameController.h"
#include <memory>


void GameController::play()
{
    cout<<endl;
    cout << "Roey Ben Harush - TicTacToe Game" << endl<<endl;
    while(1){
        cout << "Please choose your Game: " << endl;
        cout << "1. TicTacToe" << endl<<endl;
        int chooseGame;
        cin >> chooseGame;

        while (chooseGame != 1)
        {
            cerr << "Invalid game, try again" << endl<<endl;
            cin >> chooseGame;
        }

        cout << "Please choose difficulty: " << endl;
        cout << "1. Easy" << endl;
        cout << "2. Medium" << endl<<endl;

        int chooseLevel;
        cin >> chooseLevel;

        while (chooseLevel != 1 && chooseLevel != 2)
        {
            cerr << "Invalid game, try again" << endl;
            cin >> chooseLevel;
        }

        if (chooseLevel == 1 && chooseGame == 1)
        {
            curr_Game = shared_ptr<Game>(new TicTacToeLowLevel);
        }

        else if (chooseLevel == 2 && chooseGame == 1)
        {
            curr_Game = shared_ptr<Game>(new TicTacToeHighLevel);
        }   

        UI optionSelected; 
        int option;
        cout << "Please choose view option: " << endl;
        cout << "1. Console" << endl;
        cout << "2. Graphical" << endl<<endl;

       
        cin >> option;
        while (option != 1 )
        {
            if(option == 2)
                cout<<"This option is not available right now"<<endl<<"try again"<<endl;
                    
            else{
                cerr << "Invalid game, try again" << endl;
            }

            cin>>option;
        }

        optionSelected = Console;
        

        Move player_Move;
        while (!curr_Game->is_Game_End())
        {
            cout<<endl;
            curr_Game->showGame(optionSelected);

        if(chooseGame==1){
            do
            {
                player_Move = curr_Game->try_move();
            } while (!curr_Game->is_Valid_move(player_Move));
        }


            curr_Game->set_player_move(player_Move);


            if (curr_Game->is_Game_End())
            {
                cout<<endl;
                curr_Game->print_Game_End(optionSelected);
                break;
            }

            curr_Game->set_computer_move();
            if(curr_Game->is_Game_End()){
                cout<<endl;
                curr_Game->print_Game_End(optionSelected);
                break;
            }

        }
    }
}