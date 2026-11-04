#include <iostream>
using namespace std;
struct Node {
    int data;
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
        temp->next = NULL;
        if (head == NULL)
            head = temp;
        else {
            Node* p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
        }
    }
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Enter position: ";
    cin >> pos;
    Node* temp = new Node;
    temp->data = value;
    if (pos == 1) {
        temp->next = head;
        head = temp;
    } else {
        Node* p = head;
        for (int i = 1; i < pos - 1 && p != NULL; i++)
            p = p->next;
        if (p == NULL) {
            cout << "Invalid position";
            return 0;
        }
        temp->next = p->next;
        p->next = temp;
    }
    cout << "Linked List: ";
    Node* p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}
