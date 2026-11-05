#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
int main() {
    Node* head = NULL;
    int n, value, pos;
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
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Enter position: ";
    cin >> pos;
    Node* temp = new Node;
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;

    if (pos == 1) {
        temp->next = head;
        if (head != NULL)
            head->prev = temp;
        head = temp;
    } else {
        Node* p = head;
        for (int i = 1; i < pos - 1 && p != NULL; i++)
            p = p->next;
        if (p == NULL) {
            cout << "Invalid position";
            delete temp;
            return 0;
        }

        temp->next = p->next;
        temp->prev = p;
        if (p->next != NULL)
            p->next->prev = temp;

        p->next = temp;
    }
    cout << "Doubly Linked List: ";
    Node* p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}
