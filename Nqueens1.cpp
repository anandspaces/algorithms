#include <iostream>
using namespace std;

void printBoard(int** board, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int** board, int row, int col, int N) {
    // Check for conflicts in the row
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

int solveQueens(int** board, int col, int N) {
    if (col == N) {
        printBoard(board, N);
        return 1; // Found a solution
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1; // place queen

            // Recurrence to place the rest of the queens
            count += solveQueens(board, col + 1, N);

            board[i][col] = 0; // backtrack
        }
    }
    return count;
}

int main() {
    int N;
    int** board;

    cout << "Enter size of the board: ";
    cin >> N;

    if (N <= 0) {
        cerr << "Invalid board size. Please enter a positive integer." << endl;
        return 1; // Exit with an error code
    }

    board = new int*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N];
    }

    int solutions = solveQueens(board, 0, N);

    cout << "Number of solutions: " << solutions << endl;

    // Deallocate memory
    for (int i = 0; i < N; ++i) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
