#include "TicTacToe.h"

bool TicTacToe:: is_Valid_move (Move& m) const {
        if (m.get_x() != 0 && m.get_x() != 1 && m.get_x() != 2){
			std::cerr <<"Invalid move"<<std::endl;
            return false;
		}

        if (m.get_y() != 0 && m.get_y() != 1 && m.get_y() != 2){
            std::cerr <<"Invalid move"<<std::endl;
			return false;
		}
        
        if(m_board[m.get_x()][m.get_y()] != '-'){
			cerr <<"Invalid move"<<std::endl;
		    return false;
		}
        return true;
}

void TicTacToe:: set_player_move(Move& m){

    m_board[m.get_x()][m.get_y()]='X';
}

bool TicTacToe::X_won_Row() const {
	int counter = 0;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			if (m_board[i][j] == 'X') {
				counter++;
			}
		}
		if (counter == 3) {
			return true;
		}
		counter = 0;
	}
	return false;
}

bool TicTacToe::O_won_Row() const {
	int counter = 0;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			if (m_board[i][j] == 'O') {
				counter++;
			}
		}
		if (counter == 3) {
			return true;
		}
		counter = 0;
	}
	return false;
}

bool TicTacToe::X_won_col() const {
	int counter = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (m_board[i][j] == 'X') {
				counter++;
			}
		}
		if (counter == 3) {
			return true;
		}
		counter = 0;
	}
	return false;
}

bool TicTacToe::O_won_col() const {
	int counter = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (m_board[i][j] == 'O') {
				counter++;
			}
		}
		if (counter == 3) {
			return true;
		}
		counter = 0;
	}
	return false;
}

bool TicTacToe::X_won_slant()const {
	int counter = 0;
	for (int j = 0, i = 0; j < 3; j++, i++) {
		if (m_board[i][j] == 'X') {
			counter++;
		}
	}
	if (counter == 3) {
		return true;
	}
	counter = 0;

	for (int j = 0, i = 2; j < 3; j++, i--) {
		if (m_board[i][j] == 'X') {
			counter++;
		}
	}
	if (counter == 3) {
		return true;
	}
	return false;
}

bool TicTacToe::O_won_slant()const {
	int counter = 0;
	for (int j = 0, i = 0; j < 3; j++, i++) {
		if (m_board[i][j] == 'O') {
			counter++;
		}
	}
	if (counter == 3) {
		return true;
	}

	counter = 0;

	for (int j = 0, i = 2; j < 3; j++, i--) {
		if (m_board[i][j] == 'O') {
			counter++;
		}
	}
	if (counter == 3) {
		return true;
	}
	return false;
}

bool TicTacToe::Is_Game_End_Tie ()const {
	int counter = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (m_board[i][j] == '-') {
				return false;
			}
		}
	}
	return true;
}


bool TicTacToe:: is_Game_End(){
    
    if(X_won_Row() || X_won_col() || X_won_slant()){
        m_state = PlayerWins;
        return true;
    }

    else if(O_won_Row() || O_won_col() || O_won_slant()){
        m_state = ComuterWins;
        return true;
    }

    else if(Is_Game_End_Tie()){
        m_state = Tie;
        return true;
    }

    m_state = InProgress;
    return false;
}