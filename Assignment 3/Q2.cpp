#include <iostream>
using namespace std;
void printParenthesis(int i, int j, int bracket[100][100], char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i, bracket[i][j], bracket, name);
    printParenthesis(bracket[i][j] + 1, j, bracket, name);
    cout << ")";
}

int main() {
    int arr[] = {10,20,5,15,50,10,15};  // Matrix A: 2x1, B: 1x3, C: 3x4
    int n = sizeof(arr) / sizeof(arr[0]);

    // Capture output
    char name = 'A';
    int m[100][100];
    int bracket[100][100];

    // Compute MCM and store bracket
    for (int i = 1; i < n; i++) 
    m[i][i] = 0;
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = 100000000;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }

    cout << "Optimal parenthesization: ";
    printParenthesis(1, n - 1, bracket, name);
    cout << ", Multiplications performed = " << m[1][n - 1] << endl;
}