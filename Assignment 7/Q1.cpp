#include <iostream>
#include <vector>
using namespace std;
// 1. Brute Force Approach
void bruteForceSearch(string txt, string pat) {
    int N = txt.length();
    int M = pat.length();
    cout << "Brute Force: ";
    for (int i = 0; i <= N - M; i++) {
        int j = 0;
        while (j < M && txt[i + j] == pat[j]) {
            j++;
        }
        if (j == M)
            cout << "Pattern found at index " << i << endl; // 1-based
    }
}

// 2. Rabin-Karp Algorithm
void rabinKarpSearch(string txt, string pat) {
    int d = 256; // number of characters in input alphabet
    int q = 101; // A prime number
    int N = txt.length();
    int M = pat.length();
    int h = 1, p = 0, t = 0;

    // The value of h would be "pow(d, M-1)%q"
    for (int i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    cout << "Rabin-Karp: ";
    for (int i = 0; i <= N - M; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }
        // Calculate hash value for next window
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
                t += q;
        }
    }
}

// 3. KMP Algorithm
vector<int> computeLPS(string pat) {
    int M = pat.length();
    vector<int> lps(M, 0);
    int len = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}

void KMPSearch(string txt, string pat) {
    int N = txt.length();
    int M = pat.length();
    vector<int> lps = computeLPS(pat);
    int i = 0, j = 0;
    cout << "KMP: ";
    while (i < N) {
        if (pat[j] == txt[i]) {
            i++; j++;
        }
        if (j == M) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

// Main function to test all algorithms
int main() {
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";

    bruteForceSearch(txt, pat);
    rabinKarpSearch(txt, pat);
    KMPSearch(txt, pat);
}