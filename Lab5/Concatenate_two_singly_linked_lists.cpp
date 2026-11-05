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
        temp->next = NULL;

        if (head == NULL)
            head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}
int main() {
    int n, m;
    cout << "Enter number of nodes in first list: ";
    cin >> n;
    Node* head1 = createList(n);
    cout << "Enter number of nodes in second list: ";
    cin >> m;
    Node* head2 = createList(m);
    if (head1 == NULL)
        head1 = head2;
    else {
        Node* p = head1;
        while (p->next != NULL)
            p = p->next;
        p->next = head2;
    }
    cout << "Concatenated List: ";
    Node* p = head1;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}
