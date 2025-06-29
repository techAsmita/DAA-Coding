//dfs topo sort
#include <iostream>
using namespace std;
const int V = 6;
int adj[V][V] = {0};  // Adjacency matrix
bool visited[V] = {false};
int myStack[V];   // Stack for storing topological sort
int top = -1;
void dfs(int node) 
{
    visited[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !visited[i]) 
        {
            dfs(i);
        }
    }

    myStack[++top] = node;  // Push node after visiting all neighbors
}

void topoSortDFS() {
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i);
    }

    cout << "Topological Sort (DFS): ";
    while (top >= 0)
        cout << myStack[top--] << " ";
    cout << endl;
}

int main() {
    // Edges: [2->3], [3->1], [4->0], [4->1], [5->0], [5->2]
    int edges[][2] = {
        {2, 3}, {3, 1}, {4, 0},
        {4, 1}, {5, 0}, {5, 2}
    };

    int E = sizeof(edges) / sizeof(edges[0]);

    // Build adjacency matrix
    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][v] = 1;
    }

    topoSortDFS();
}