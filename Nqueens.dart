const int N = 8; // Size of the chessboard

// Function to print the chessboard
void printBoard(List<List<int>> board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            print("${board[i][j]} ");
        }
        print("\n");
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(List<List<int>> board, int row, int col) {
    // Check the row on the left side
    for (int i = 0; i < col; ++i) {
        if (board[row][i]==1) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]==1) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
        if (board[i][j]==1) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the Eight Queens problem
bool solveNQueens(List<List<int>> board, int col) {
    if (col == N) {
        // All queens are placed successfully, print the solution
        printBoard(board);
        print("\n");
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
    List<List<int>> board = List.generate(N, (index) => List<int>.filled(N,0)); // Initialize the chessboard with 0
    
    if (!solveNQueens(board, 0)) {
        print("Solution does not exist!/n");
    }

    return 0;
}
