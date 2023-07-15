#include<iostream>
#include<cstring>
using namespace std;

// Function to check if any player has won
bool checkWin(char board[][3], char player) {
    // Checking rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    // Checking columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Checking diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to display the board
void displayBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    char board[3][3];
    memset(board, '-', sizeof(board)); // Initializing board with '-'
    int row, col, moves = 0;
    bool gameOver = false;
    char player = 'X';

    while (!gameOver) {
        displayBoard(board);
        cout << "Player " << player << "'s turn. Enter row and column (1-3): ";
        cin >> row >> col;
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != '-') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        board[row - 1][col - 1] = player;
        moves++;
        if (checkWin(board, player)) {
            displayBoard(board);
            cout << "Player " << player << " wins!" << endl;
            gameOver = true;
        }
        else if (moves == 9) {
            displayBoard(board);
            cout << "It's a tie!" << endl;
            gameOver = true;
        }
        player = (player == 'X') ? 'O' : 'X'; // Switching players
    }
    return 0;
}