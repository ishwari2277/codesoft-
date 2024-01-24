#include <iostream>
using namespace std;

// Function to display board graphically
void displayBoard(char board[3][3]) {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            if (j > 0) cout << "|";
            cout << board[i][j];
        }
        cout << "\n";
        if (i < 2) cout << "  -----\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // If there is an empty cell, the game is not a draw
            }
        }
    }
    return true; // All cells are filled, and no player has won, so it's a draw
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // Initialize 3x3 Tic-Tac-Toe board
    char currentPlayer = 'X';
    bool gameWon = false;

    cout << "Welcome to Tic-Tac-Toe!\n";

    do {
        // Display the current state of the board
        cout << "Current Board:\n";
        displayBoard(board);

        // Prompt the current player to enter their move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the selected cell is valid and not already taken
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            // Update the board with the player's move
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                gameWon = true;
                cout << "Player " << currentPlayer << " wins!\n";
            } else {
                // Check draw
                if (checkDraw(board)) {
                    cout << "It's a draw!\n";
                    break;
                }
                // Switch players for the next turn
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move. Try again.\n";
        }

    } while (!gameWon);

    cout << "Final Board:\n";
    displayBoard(board);

    return 0;
}


