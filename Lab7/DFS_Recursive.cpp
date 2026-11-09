#include <iostream>
#include <vector>
using namespace std;
void DFS(vector<int> graph[], bool visited[], int vertex) {
    visited[vertex] = true;
    cout << vertex << " ";
    for (int neighbour : graph[vertex]) {
        if (!visited[neighbour])
            DFS(graph, visited, neighbour);
    }
}
int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    vector<int> graph[100];
    bool visited[100] = {};
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (source destination):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    if (start >= 0 && start < vertices) {
        cout << "DFS Traversal: ";
        DFS(graph, visited, start);
    } else {
        cout << "Invalid starting vertex.";
    }
    cout << endl;
    return 0;
}
