
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
Node* findLoopStart() {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
void createCycle(int position) {
    if (head == nullptr || position <= 0) {
        return;
    }
    Node* temp = head;
    Node* loopNode = nullptr;
    int count = 1;
    while (temp->next != nullptr) {
        if (count == position) {
            loopNode = temp;
        }
    temp = temp->next;
        count++;
    }
    if (count == position) {
        loopNode = temp;
    }
    if (loopNode != nullptr) {
        temp->next = loopNode;
    }
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
    cout << "Enter position to create loop (0 for no loop): ";
    cin >> position;
    createCycle(position);
    Node* result = findLoopStart();
    if (result != nullptr) {
        cout << "Loop starts at node: " << result->data;
    } else {
        cout << "No loop found";
    }
    return 0;
}
