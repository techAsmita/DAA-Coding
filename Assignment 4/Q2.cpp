#include <iostream>
using namespace std;
#define N 9 //fixed value.
// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}
// Check if placing num in grid[row][col] is valid
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Row check
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Column check
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    // 3x3 box check
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Backtracking function to solve Sudoku
bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool emptyFound = false;

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                emptyFound = true;
                break;
            }
        }
        if (emptyFound)
            break;
    }

    // No empty cell found, puzzle solved
    if (!emptyFound)
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0; // Backtrack
        }
    }

    return false; // Trigger backtracking
}

int main() {
    int grid[N][N] = {
        {3, 0, 6, 5, 7, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 8, 6, 3, 0, 0}
    };

    cout << "Given Sudoku Grid:\n";
    printGrid(grid);

    cout << "\nSolved Sudoku Grid:\n";
    if (solveSudoku(grid))
        printGrid(grid);
    else
        cout << "No solution exists!" << endl;
}