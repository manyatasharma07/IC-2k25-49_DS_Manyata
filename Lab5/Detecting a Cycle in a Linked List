
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = nullptr;
void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}
bool detectCycle() {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
void createCycle() {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head->next;
}
int main() {
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        insert(value);
    }
    int choice;
    cout << "Create cycle? (1 for Yes, 0 for No): ";
    cin >> choice;
    if (choice == 1) {
        createCycle();
    }
    if (detectCycle()) {
        cout << "Cycle detected in linked list";
    } else {
        cout << "No cycle found in linked list";
    }
    return 0;
}
