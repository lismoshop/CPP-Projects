#include <iostream>
using namespace std;

int main() {

    char player = 'X';
    bool playerChanceFlag = 1;
    int tutorial[3][3] = {11, 12, 13, 21, 22, 23, 31, 32, 33};
    bool gameState = 1;
    int spotFill;
    char tictactoe[3][3] = {32 ,32, 32, 32, 32, 32, 32, 32, 32};
    bool moderation[3][3] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << "*********************** TIC-TAC-TOE ************************" << endl;
   
    cout << "It must be in {row, column} format i.e., {'11','12','13','21','22','23','31','32','33'}" << endl;
    while(gameState) {

        if(playerChanceFlag == 0) {
            player = 'O';
        } else {
            player = 'X';
        }

        cout << "Where would you like to put " << player << " on the board: ";
        cin >> spotFill;
        
        
        // spotFill cases
        
        switch (spotFill)
        {
        case 11:
            if(moderation[0][0] == 1) {
                tictactoe[0][0] = player;
                moderation[0][0] = 0;
                break;
            } else {
                cout << "THE SPOT IS ALREADY USED TRY ANOTHER." << endl; playerChanceFlag = !playerChanceFlag; break;
            }
            
        case 12:
            if(moderation[0][1] == 1) {
                tictactoe[0][1] = player;
                moderation[0][1] = 0;
                break;
            } else{
                cout << "THE SPOT IS ALREADY USED TRY ANOTHER." << endl; playerChanceFlag = !playerChanceFlag; break;
            }
        case 13:
            if(moderation[0][2] == 1) {
                tictactoe[0][2] = player;
                moderation[0][2] = 0;
                break;
            } else{
                cout << "THE SPOT IS ALREADY USED TRY ANOTHER." << endl; playerChanceFlag = !playerChanceFlag; break;
            }
        case 21:
            if(moderation[1][0] == 1) {
                tictactoe[1][0] = player;
                moderation[1][0] = 0;
                break;
            } else{
                cout << "THE SPOT IS ALREADY USED TRY ANOTHER." << endl; playerChanceFlag = !playerChanceFlag; break;
            }
        case 22:
            if(moderation[1][1] == 1) {
                tictactoe[1][1] = player;
                moderation[1][1] = 0;
                break;
            } else{
                cout << "THE SPOT IS ALREADY USED TRY ANOTHER." << endl; playerChanceFlag = !playerChanceFlag; break;
            }
        case 23:
            if(moderation[1][2] == 1) {
                tictactoe[1][2] = player;
                moderation[1][2] = 0;
                break;
            } else{
                cout << "THE SPOT IS ALREADY USED TRY ANOTHER." << endl; playerChanceFlag = !playerChanceFlag; break;
            }
        case 31:
            if(moderation[2][0] == 1) {
                tictactoe[2][0] = player;
                moderation[2][0] = 0;
                break;
            } else{
                cout << "THE SPOT IS ALREADY USED TRY ANOTHER." << endl; playerChanceFlag = !playerChanceFlag; break;
            }
        case 32:
            if(moderation[2][1] == 1) {
                tictactoe[2][1] = player;
                moderation[2][1] = 0;
                break;
            } else{
                cout << "THE SPOT IS ALREADY USED TRY ANOTHER." << endl; playerChanceFlag = !playerChanceFlag; break;
            }
        case 33:
            if(moderation[2][2] == 1) {
                tictactoe[2][2] = player;
                moderation[2][2] = 0;
                break;
            } else{
                cout << "THE SPOT IS ALREADY USED TRY ANOTHER." << endl; playerChanceFlag = !playerChanceFlag; break;
            }
        default:
            cout << "that is not a valid coord. It must be in {row, column} format i.e., {'11','12','13','21','22','23','31','32','33'}" << endl;
            playerChanceFlag = !playerChanceFlag;
            break;
        }

    // CHECKS FOR WINNERS.
        // ROW CHECK    
        if(tictactoe[0][0] == tictactoe [0][1] && tictactoe[0][1] == tictactoe[0][2] && (tictactoe[0][0] == 'X' || tictactoe[0][0] == 'O')) {
            gameState = 0;
            break;
        }else if(tictactoe[1][0] == tictactoe [1][1] && tictactoe[1][1] == tictactoe[1][2] && (tictactoe[1][0] == 'X' || tictactoe[1][0] == 'O')) {
            gameState = 0;
            break;
        }else if(tictactoe[2][0] == tictactoe [2][1] && tictactoe[0][1] == tictactoe[2][2] && (tictactoe[2][0] == 'X' || tictactoe[2][0] == 'O')) {
            gameState = 0;
            break;
        }
        
        // COLUMN CHECK
        else if(tictactoe[0][0] == tictactoe [1][0] && tictactoe[1][0] == tictactoe[2][0] && (tictactoe[0][0] == 'X' || tictactoe[0][0] == 'O')) {
            gameState = 0;
            break;
        }else if(tictactoe[0][1] == tictactoe [1][1] && tictactoe[1][1] == tictactoe[2][1] && (tictactoe[0][1] == 'X' || tictactoe[0][1] == 'O')) {
            gameState = 0;
            break;
        }else if(tictactoe[0][2] == tictactoe [1][2] && tictactoe[1][2] == tictactoe[1][2] && (tictactoe[0][2] == 'X' || tictactoe[0][2] == 'O')) {
            gameState = 0;
            break;
        }
        // CROSS CHECK
        else if(tictactoe[0][0] == tictactoe [1][1] && tictactoe[1][1] == tictactoe[2][2] && (tictactoe[0][0] == 'X' || tictactoe[0][0] == 'O')) {
            gameState = 0;
            break;
        }else if(tictactoe[0][2] == tictactoe [1][1] && tictactoe[1][1] == tictactoe[2][0] && (tictactoe[1][1] == 'X' || tictactoe[1][1] == 'O')) {
            gameState = 0;
            break;
        }
        // Prints the board
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout << "| " <<tictactoe[i][j] << " ";
            }cout<< "|" << endl << "-------------" << endl;
        }


        // Switches the player
        playerChanceFlag = !playerChanceFlag;
        continue;
    }

    if(gameState == 0) {

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout << "| " <<tictactoe[i][j] << " ";
            }cout<< "|" << endl << "-------------" << endl;
        }
        cout << " The Winner is: \"" << player << "\"" << endl;
    }

    cout << "*****************************************************************";
}