#include <iostream>
#include <stdlib.h>
using namespace std;

// Array for the board
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
// Variable Declaration
int choice;
int row, column;
char turn = 'X';
bool draw = false;

// Function to display the current status of the gaming board
void display_board() {
    cout << "PLAYER - 1 [X]  PLAYER - 2 [O]\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout << "     |     |     \n";
}

// Function to handle the player's turn
void player_turn() {
    if (turn == 'X') {
        cout << "Player - 1 [X] turn: ";
    } else {
        cout << "Player - 2 [O] turn: ";
    }

    cin >> choice;

    // Map choice to board coordinates
    switch (choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid Move! Please choose a valid number.\n";
            return;
    }

    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    } else {
        cout << "Box already filled! Please choose another!\n";
    }
}

// Function to check the game status
bool gameover() {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return false;
        }
    }

    // Check diagonals for a win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return false;
    }

    // Check for ongoing game
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return true;
            }
        }
    }

    // If no win and no empty spaces, it's a draw
    draw = true;
    return false;
}

// Main function
int main() {
    cout << "TIC TAC TOE GAME\n";
    cout << "FOR 2 PLAYERS\n";

    while (gameover()) {
        display_board();
        player_turn();
    }

    display_board();

    if (draw) {
        cout << "GAME DRAW!!!\n";
    } else {
        cout << "Congratulations! Player with '" << (turn == 'X' ? 'O' : 'X') << "' has won the game!\n";
    }

    return 0;
}
