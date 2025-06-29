//kosaraju sharir algo
#include <iostream>
using namespace std;
#define MAX 100
int V;
int adj[MAX][MAX];      // Adjacency matrix of original graph
int rev[MAX][MAX];      // Adjacency matrix of reversed graph
bool visited[MAX];
int stack1[MAX];
int top = -1;
void push(int v) {
    stack1[++top] = v;
}
int pop() {
    return stack1[top--];
}

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i])
            dfs(i);
    }
    push(v);
}

// DFS for the reversed graph
void reverseDfs(int v) {
    visited[v] = true;
    for (int i = 0; i < V; i++) {
        if (rev[v][i] && !visited[i])
            reverseDfs(i);
    }
}

int countSCCs() {
    // Step 1: Fill stack with vertices in finishing time order
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i);
    }
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    int count = 0;
    while (top >= 0) {
        int v = pop();
        if (!visited[v]) {
            reverseDfs(v);
            count++;
        }
    }
    return count;
}
int main() {
    V = 5;
    // Edges: 0->2, 2->1, 1->0, 0->3, 3->4
    adj[0][2] = 1;
    adj[2][1] = 1;
    adj[1][0] = 1;
    adj[0][3] = 1;
    adj[3][4] = 1;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j])
                rev[j][i] = 1;
        }
    }

    int result = countSCCs();
    cout << "Number of Strongly Connected Components: " << result << endl;
}