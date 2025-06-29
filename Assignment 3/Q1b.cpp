#include <iostream>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }

void printLPS(char* str, int n) {
    int dp[100][100];

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int k = 2; k <= n; k++) {
        for (int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1;
            if (str[i] == str[j] && k == 2)
                dp[i][j] = 2;
            else if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    int index = dp[0][n - 1];
    char lps[100];
    lps[index] = '\0';  // null terminate

    int i = 0, j = n - 1;
    int start = 0, end = index - 1;

    while (i <= j) {
        if (str[i] == str[j]) {
            lps[start] = str[i];
            lps[end] = str[j];
            i++; j--; start++; end--;
        } else if (dp[i + 1][j] > dp[i][j - 1])
            i++;
        else
            j--;
    }

    cout << "Length of LPS = " << dp[0][n - 1] << endl;
    cout << "Longest Palindromic Subsequence = " << lps << endl;
}

int main() {
    char seq[] = "BBABCBCAB";
    int n = 9;
    printLPS(seq, n);
}