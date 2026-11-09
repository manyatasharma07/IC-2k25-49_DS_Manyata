#include <iostream>
#include <vector>
using namespace std;
int main() {
    int vertices, edges, directed;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    vector<int> graph[100];
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Directed graph? (1 = Yes, 0 = No): ";
    cin >> directed;
    cout << "Enter edges (source destination):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            graph[u].push_back(v);

            if (!directed)
                graph[v].push_back(u);
        } else {
            cout << "Invalid edge. Enter valid vertices.\n";
            i--;
        }
    }
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";

        for (int neighbour : graph[i])
            cout << neighbour << " ";
        cout << endl;
    }
    return 0;
}
