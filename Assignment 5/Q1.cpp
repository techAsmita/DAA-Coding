//hamiltonian graph
#include <iostream>
using namespace std;
const int V=5; // Number of vertices in the graph
int graph[V][V];

bool isSafe(int v, int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

// Recursive function to find Hamiltonian Cycle
bool hamCycleUtil(int path[], int pos) {
    // Base case: If all vertices are in the path
    if (pos == V) {
        // Condition 3: Check if last vertex connects to the first
        return graph[path[pos - 1]][path[0]] == 1;
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(v, path, pos)) {
            path[pos] = v;

            if (hamCycleUtil(path, pos + 1))
                return true;

            path[pos] = -1;//#backtrack
        }
    }
    return false;
}

void hamiltonianCycle() {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; 

    if (!hamCycleUtil(path, 1)) {
        cout << "No Hamiltonian Cycle exists\n";
        return;
    }

    cout << "Hamiltonian Cycle: ";
    for (int i = 0; i < V; i++)
       { cout << path[i] << " ";}
    cout << path[0] << endl;
}

int main() {
    int inputGraph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = inputGraph[i][j];

    hamiltonianCycle();
}