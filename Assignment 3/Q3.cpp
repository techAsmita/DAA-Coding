#include <iostream>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }

int Knapsack(int W, int wt[], int val[], int n) {
    int dp[100][100];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    int res = dp[n][W];
    int w = W;

    cout << "Items selected: ";
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i - 1][w]) continue;  // Item not included
        else {
            cout << i << " "; // Print item index (1-based)
            res -= val[i - 1];
            w -= wt[i - 1];
        }
    }
    cout << " Maximum profit: " << dp[n][W] << endl;
    return dp[n][W];
}

int main() {
    int val[] = {5, 3, 8, 6};
    int wt[] = {2, 3, 4, 5};
    int W = 7;
    int n = 4;
    Knapsack(W, wt, val, n);
    return 0;
}