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
void findMiddle() {
    if (head == nullptr) {
        cout << "Linked list is empty";
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element: " << slow->data;
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
    findMiddle();
    return 0;
}
