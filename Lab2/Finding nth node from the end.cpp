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
void findNthFromEnd(int n) {
    Node* slow = head;
    Node* fast = head;
    for (int i = 0; i < n; i++) {
        if (fast == nullptr) {
            cout << "Invalid position";
            return;
        }
        fast = fast->next;
    }
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    cout << "Nth node from end: " << slow->data;
}
int main() {
    int n, value, position;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        insert(value);
    }
    cout << "Enter position from end: ";
    cin >> position;
    if (position <= 0) {
        cout << "Invalid position";
    } else {
        findNthFromEnd(position);
    }
    return 0;
}
