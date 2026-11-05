#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* createList(int n) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        Node* temp = new Node;
        cout << "Enter value: ";
        cin >> temp->data;

        if (head == NULL) {
            head = tail = temp;
            temp->next = head;
        } else {
            tail->next = temp;
            tail = temp;
            tail->next = head;
        }
    }
    return head;
}
int main() {
    int n, m;
    cout << "Enter nodes in first list: ";
    cin >> n;
    Node* head1 = createList(n);
    cout << "Enter nodes in second list: ";
    cin >> m;
    Node* head2 = createList(m);

    if (head1 == NULL)
        head1 = head2;
    else if (head2 != NULL) {
        Node* tail1 = head1;
        Node* tail2 = head2;
        while (tail1->next != head1)
            tail1 = tail1->next;
        while (tail2->next != head2)
            tail2 = tail2->next;
        tail1->next = head2;
        tail2->next = head1;
    }
    cout << "Concatenated Circular List: ";
    if (head1 != NULL) {
        Node* p = head1;
        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != head1);
    }
    return 0;
}
