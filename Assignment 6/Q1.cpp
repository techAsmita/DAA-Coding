//ford fulkerson algo
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
#define V 6 // Number of vertices

bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

// Ford-Fulkerson algorithm
int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;

    int rGraph[V][V]; // Residual graph
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;

        // Find minimum flow in the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // Update residual capacities
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    // Adjacency matrix of the graph
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},  // From 0
        {0, 0, 10, 12, 0, 0},  // From 1
        {0, 4, 0, 0, 14, 0},   // From 2
        {0, 0, 9, 0, 0, 20},   // From 3
        {0, 0, 0, 7, 0, 4},    // From 4
        {0, 0, 0, 0, 0, 0}     // From 5
    };
    cout << "Maximum Flow: " << fordFulkerson(graph, 0, 5) << endl;
}