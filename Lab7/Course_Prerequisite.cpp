#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void topologicalSort(vector<int> graph[], int vertices) {
    int indegree[100] = {};
    for (int i = 0; i < vertices; i++) {
        for (int neighbour : graph[i])
            indegree[neighbour]++;
    }
    queue<int> q;
    for (int i = 0; i < vertices; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> order;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        order.push_back(current);
        for (int neighbour : graph[current]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    if (order.size() != vertices) {
        cout << "Circular prerequisite detected. No valid course order exists.\n";
    } else {
        cout << "\nValid Course Completion Order:\n";
        for (int course : order)
            cout << "Course " << course << " ";
        cout << endl;
    }
}
int main() {
    int vertices, edges;
    cout << "Enter number of courses: ";
    cin >> vertices;
    if (vertices <= 0 || vertices > 100) {
        cout << "Invalid number of courses.\n";
        return 0;
    }
    vector<int> graph[100];
    cout << "Enter number of prerequisites: ";
    cin >> edges;
    cout << "Enter prerequisite pairs (prerequisite course, dependent course):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= vertices || v < 0 || v >= vertices || u == v) {
            cout << "Invalid course pair.\n";
            i--;
            continue;
        }
        graph[u].push_back(v);
    }
    topologicalSort(graph, vertices);
    return 0;
}
