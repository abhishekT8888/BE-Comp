#include <iostream>
#include <vector>

using namespace std;

// Function to check if a Queen can be placed on board[row][col]
bool isSafe(vector<vector<int>> &board, int row, int col, int N) {
    // Check this column on the upper side
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Backtracking function to solve N-Queens problem
bool solveNQueens(vector<vector<int>> &board, int row, int N) {
    // Base case: If all queens are placed, return true
    if (row >= N)
        return true;

    // If a queen has already been placed in this row, skip to the next row
    for (int col = 0; col < N; col++) {
        if (board[row][col] == 1) {
            return solveNQueens(board, row + 1, N);
        }
    }

    // Try placing a queen in each column for the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            // Place the queen
            board[row][col] = 1;

            // Recursively place the remaining queens
            if (solveNQueens(board, row + 1, N))
                return true;

            // If placing the queen in board[row][col] leads to no solution, remove the queen
            board[row][col] = 0;
        }
    }

    // If the queen cannot be placed in any column, return false
    return false;
}

// Function to print the N-Queens matrix
void printBoard(vector<vector<int>> &board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N, initRow, initCol;

    // Input the size of the board (N x N) and the initial position of the first queen
    cout << "Enter the value of N (size of board): ";
    cin >> N;
    
    vector<vector<int>> board(N, vector<int>(N, 0));  // Initialize the N x N board with all 0s

    cout << "Enter the row and column of the first Queen (0-indexed): ";
    cin >> initRow >> initCol;

    // Place the first Queen
    board[initRow][initCol] = 1;

    // Start solving from the next row after placing the first queen
    if (solveNQueens(board, 0, N)) {
        cout << "The solution to the N-Queens problem is:\n";
        printBoard(board, N);
    } else {
        cout << "No solution exists for the given initial configuration.\n";
    }

    return 0;
}
