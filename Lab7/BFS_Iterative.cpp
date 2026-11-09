#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(vector<int> graph[], int vertices, int start) {
    bool visited[100] = {};
    queue<int> q;
    visited[start] = true;
    q.push(start);
    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for (int neighbour : graph[current]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    vector<int> graph[100];
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
    if (start >= 0 && start < vertices)
        BFS(graph, vertices, start);
    else
        cout << "Invalid starting vertex.";
    cout << endl;
    return 0;
}
