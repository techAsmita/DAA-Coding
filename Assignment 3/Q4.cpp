#include <iostream>
using namespace std;
int min(int a, int b, int c) {
    int m = (a < b) ? a : b;
    return (m < c) ? m : c;
}
int maxSquareArea(int mat[100][100], int n, int m) {
    int dp[100][100];
    int maxSide = 0;

    // Copy first row and column
    for (int i = 0; i < n; i++) {
        dp[i][0] = mat[i][0];
        if (dp[i][0] > maxSide) maxSide = dp[i][0];
    }
    for (int j = 0; j < m; j++) {
        dp[0][j] = mat[0][j];
        if (dp[0][j] > maxSide) maxSide = dp[0][j];
    }

    // Build the dp table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][j] == 1)
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
            else
                dp[i][j] = 0;

            if (dp[i][j] > maxSide)
                maxSide = dp[i][j];
        }
    }

    cout << "Maximum size of square sub-matrix with all 1s: " << maxSide << endl;
    cout << "Area of that square: " << (maxSide * maxSide) << endl;

    return maxSide * maxSide;
}
int main() {
    int mat[100][100] = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };
    int n = 6, m = 5;
    maxSquareArea(mat, n, m);
}