#include <iostream>
using namespace std;

struct Node {
    int data;
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
    cout << "Enter position to delete: ";
    cin >> pos;
    if (head == NULL || pos < 1) {
        cout << "Invalid position";
        return 0;
    }
    Node* temp;
    if (pos == 1) {
        temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* p = head;
        for (int i = 1; i < pos - 1 && p != NULL; i++)
            p = p->next;
        if (p == NULL || p->next == NULL) {
            cout << "Invalid position";
            return 0;
        }
        temp = p->next;
        p->next = temp->next;
        delete temp;
    }
    cout << "Linked List: ";
    Node* p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}
