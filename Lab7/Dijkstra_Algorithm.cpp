#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
void dijkstra(vector<pair<int, int>> graph[], int vertices, int start) {
    vector<int> distance(vertices, INT_MAX);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    distance[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();
        if (currentDistance > distance[currentVertex])
          continue;
        for (auto edge : graph[currentVertex]) {
            int neighbour = edge.first;
            int weight = edge.second;

            if (distance[currentVertex] + weight < distance[neighbour]) {
                distance[neighbour] = distance[currentVertex] + weight;
                pq.push({distance[neighbour], neighbour});
            }
        }
    }
    cout << "\nShortest distances from vertex " << start << ":\n";
    for (int i = 0; i < vertices; i++) {
        cout << start << " to " << i << " = ";

        if (distance[i] == INT_MAX)
            cout << "Unreachable";
        else
            cout << distance[i];
        cout << endl;
    }
}
int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    if (vertices <= 0 || vertices > 100) {
        cout << "Invalid number of vertices.\n";
        return 0;
    }
    vector<pair<int, int>> graph[100];
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        if (u < 0 || u >= vertices || v < 0 || v >= vertices || weight < 0) {
            cout << "Invalid edge or negative weight.\n";
            i--;
            continue;
        }
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    if (start >= 0 && start < vertices)
        dijkstra(graph, vertices, start);
    else
        cout << "Invalid starting vertex.\n";
    return 0;
}
