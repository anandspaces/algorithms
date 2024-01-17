#include <iostream>
using namespace std;

const int N = 8; // Size of the chessboard

// Function to print the chessboard
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check the row on the left side
    for (int i = 0; i < col; ++i) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the Eight Queens problem
bool solveNQueens(int board[N][N], int col) {
    if (col == N) {
        // All queens are placed successfully, print the solution
        printBoard(board);
        cout << endl;
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place queen

            // Recur to place rest of the queens
            res = solveNQueens(board, col + 1) || res;

            // If placing queen in the current position doesn't lead to a solution
            // then remove the queen from the current position (backtrack)
            board[i][col] = 0;
        }
    }

    return res;
}

int main() {
    int board[N][N] = {0}; // Initialize the chessboard with 0

    if (!solveNQueens(board, 0)) {
        cout << "Solution does not exist!" << endl;
    }

    return 0;
}
