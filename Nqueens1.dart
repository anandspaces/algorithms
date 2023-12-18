import 'dart:io';

void main() {
  const int N = 8; // Size of the chessboard
  List<List<int>> board = List.generate(N, (index) => List<int>.filled(N, 0));

  if (!solveNQueens(board, 0)) {
    print("Solution does not exist!");
  }
}

void printBoard(List<List<int>> board) {
  for (int i = 0; i < board.length; ++i) {
    for (int j = 0; j < board[i].length; ++j) {
      stdout.write("${board[i][j]} ");
    }
    print("");
  }
}

bool isSafe(List<List<int>> board, int row, int col) {
  for (int i = 0; i < col; ++i) {
    if (board[row][i] == 1) {
      return false;
    }
  }

  for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
    if (board[i][j] == 1) {
      return false;
    }
  }

  for (int i = row, j = col; i < board.length && j >= 0; ++i, --j) {
    if (board[i][j] == 1) {
      return false;
    }
  }

  return true;
}

bool solveNQueens(List<List<int>> board, int col) {
  if (col == board.length) {
    printBoard(board);
    print("");
    return true;
  }

  bool res = false;
  for (int i = 0; i < board.length; ++i) {
    if (isSafe(board, i, col)) {
      board[i][col] = 1;
      res = solveNQueens(board, col + 1) || res;
      board[i][col] = 0;
    }
  }

  return res;
}
