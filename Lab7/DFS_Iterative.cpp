#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void DFS(vector<int> graph[], int vertices, int start) {
    bool visited[100] = {};
    stack<int> s;
    s.push(start);
    cout << "DFS Traversal: ";
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        if (!visited[current]) {
            visited[current] = true;
            cout << current << " ";
            for (int i = graph[current].size() - 1; i >= 0; i--) {
                int neighbour = graph[current][i];
                if (!visited[neighbour])
                  s.push(neighbour);
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
        DFS(graph, vertices, start);
    else
        cout << "Invalid starting vertex.";
    cout << endl;
    return 0;
}
