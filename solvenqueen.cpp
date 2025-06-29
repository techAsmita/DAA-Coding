#include <iostream>
using namespace std;
#define Q 4

void printb(int board[Q][Q]) {
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < Q; j++) {
            cout << (board[i][j] ? "Q " : "_ ");
        }
        cout << endl;
    }
    cout << endl;
}

bool issafe(int board[Q][Q], int r, int c) {
    // Check same column
    for (int i = 0; i < r; i++) {
        if (board[i][c])
            return false;
    }

    // Check upper-left diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check upper-right diagonal
    for (int i = r, j = c; i >= 0 && j < Q; i--, j++) {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solve(int board[Q][Q], int r) {
    if (r >= Q)
        return true;

    for (int c = 0; c < Q; c++) {  // start from 0, not 1
        if (issafe(board, r, c)) {
            board[r][c] = 1;

            if (solve(board, r + 1))
                return true;

            // backtrack
            board[r][c] = 0;
        }
    }
    return false;
}

int main() {
    int board[Q][Q] = {0};
    if (solve(board, 0)) {
        printb(board);
    } else {
        cout << "No solution exists." << endl;
    }
}
