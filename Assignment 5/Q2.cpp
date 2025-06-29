//topological sort using kahn's algorithm
#include <iostream>
using namespace std;
const int V = 6;
int adj[V][V] = {0};
int indegree[V] = {0};
int myQueue[V]; 
int front = 0, rear = -1;
void topoSortKahn() {
    // Calculate indegrees
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (adj[i][j])
                indegree[j]++;

    // Enqueue all vertices with indegree 0
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            myQueue[++rear] = i;

    cout << "Topological Sort (Kahn's): ";

    while (front <= rear) {
        int node = myQueue[front++];  // dequeue
        cout << node << " ";

        // Decrease indegree of neighbors
        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    myQueue[++rear] = i;
            }
        }
    }
    cout << endl;
}

int main() {
    int edges[][2] = {
        {2, 3}, {3, 1}, {4, 0},
        {4, 1}, {5, 0}, {5, 2}
    };
    int n = sizeof(edges) / sizeof(edges[0]);
    // Build adjacency matrix
    for (int i = 0; i < n; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][v] = 1;
    }

    topoSortKahn();
}