#include <iostream>
using namespace std;
#define V 4 // Number of vertices
bool isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

void graphColoring(int graph[V][V], int m) {
    int color[V] = {0};
    if (graphColoringUtil(graph, m, color, 0)) {
        cout << "Solution exists:\n";
        for (int i = 0; i < V; i++)
            cout << "Vertex " << i << " ---> Color " << color[i] << endl;
    } else {
        cout << "No solution exists";
    }
}
int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; // Number of colors
    graphColoring(graph, m);
}