#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
int main() {
    Node* head = NULL;
    int n, pos;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Node* temp = new Node;
        cout << "Enter value: ";
        cin >> temp->data;
        temp->prev = NULL;
        temp->next = NULL;

        if (head == NULL)
            head = temp;
        else {
            Node* p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
            temp->prev = p;
        }
    }
    cout << "Enter position to delete: ";
    cin >> pos;

    if (head == NULL || pos < 1) {
        cout << "Invalid position";
        return 0;
    }
    Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Invalid position";
        return 0;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    delete temp;
    cout << "Doubly Linked List: ";
    Node* p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}
