#include <iostream>
#include <vector>
#include <string>
using namespace std;
void displayFriends(vector<string>& people, vector<int> graph[], int person) {
    cout << "Friends of " << people[person] << ": ";
    if (graph[person].empty()) {
        cout << "No friends";
    }
    for (int friendID : graph[person])
        cout << people[friendID] << " ";
    cout << endl;
}
void friendsOfFriends(vector<string>& people, vector<int> graph[], int person) {
    vector<bool> direct(people.size(), false);
    vector<bool> shown(people.size(), false);
    direct[person] = true;
    for (int friendID : graph[person])
        direct[friendID] = true;
    cout << "Friends of friends of " << people[person] << ": ";
    bool found = false;
    for (int friendID : graph[person]) {
        for (int secondFriend : graph[friendID]) {
            if (!direct[secondFriend] && !shown[secondFriend]) {
                cout << people[secondFriend] << " ";
                shown[secondFriend] = true;
                found = true;
            }
        }
    }
    if (!found)
        cout << "None";
    cout << endl;
}
void DFS(int vertex, vector<int> graph[], vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << " ";
    for (int neighbour : graph[vertex]) {
        if (!visited[neighbour])
            DFS(neighbour, graph, visited);
    }
}
void connectedComponents(vector<int> graph[], int vertices) {
    vector<bool> visited(vertices, false);
    int components = 0;
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            components++;
            cout << "\nGroup " << components << ": ";
            DFS(i, graph, visited);
        }
    }
    cout << "\nTotal connected groups: " << components << endl;
}
int main() {
    int n, choice;
    cout << "Enter number of people: ";
    cin >> n;
    if (n <= 0 || n > 100) {
        cout << "Invalid number of people.\n";
        return 0;
    }
    vector<string> people(n);
    vector<int> graph[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter name of person " << i << ": ";
        cin >> people[i];
    }
    do {
        cout << "\n1. Add Friendship\n2. Display Friends\n3. Friends of Friends\n4. Connected Components\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        int u, v;
        switch (choice) {
            case 1:
                cout << "Enter two person IDs: ";
                cin >> u >> v;
                if (u < 0 || u >= n || v < 0 || v >= n || u == v) {
                    cout << "Invalid person IDs.\n";
                    break;
                }
                graph[u].push_back(v);
                graph[v].push_back(u);
                cout << "Friendship added.\n";
                break;
            case 2:
                cout << "Enter person ID: ";
                cin >> u;
                if (u >= 0 && u < n)
                    displayFriends(people, graph, u);
                else
                    cout << "Invalid person ID.\n";
                break;
            case 3:
                cout << "Enter person ID: ";
                cin >> u;
                if (u >= 0 && u < n)
                    friendsOfFriends(people, graph, u);
                else
                    cout << "Invalid person ID.\n";
                break;
            case 4:
                connectedComponents(graph, n);
                break;
            case 5:               
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);
    return 0;
}
