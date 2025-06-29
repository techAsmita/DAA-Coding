#include <iostream>
using namespace std;
int max(int a, int b) 
{ return (a > b) ? a : b; }

void LCS(char* X, char* Y, int m, int n) {
    int L[100][100]; // assuming size < 100
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) 
            L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]) L[i][j] = L[i - 1][j - 1] + 1;
            else L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    int i = m, j = n;
    char lcs[100];
    int index = L[m][n];
    lcs[index] = '\0';

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--; j--; index--;
        } 
        else if (L[i - 1][j] > L[i][j - 1]) i--;
        else j--;
    }
    cout << "Longest Common Subsequence = " << lcs<< endl;
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    LCS(X, Y, 6, 7);
}