#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
int main() {
    Node* head = NULL;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Node* temp = new Node;
        cout << "Enter value: ";
        cin >> temp->data;

        if (head == NULL) {
            head = temp;
            temp->next = head;
        } else {
            Node* p = head;
            while (p->next != head)
                p = p->next;
            p->next = temp;
            temp->next = head;
        }
    }
    if (head != NULL && head->next != head) {
        Node* prev = head;
        Node* current = head->next;
        Node* next;

        while (current != head) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head->next = prev;
        head = prev;
    }
    cout << "Reversed Circular List: ";
    if (head != NULL) {
        Node* p = head;

        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
    }
    return 0;
}
