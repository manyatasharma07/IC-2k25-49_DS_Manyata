#include <iostream>
using namespace std;
int main() {
    int vertices, edges, directed;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    int graph[100][100] = {};
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Directed graph? (1 = Yes, 0 = No): ";
    cin >> directed;
    cout << "Enter edges (source destination):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            graph[u][v] = 1;

            if (!directed)
                graph[v][u] = 1;
        } else {
            cout << "Invalid edge. Enter valid vertices.\n";
            i--;
        }
    }
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    return 0;
}
