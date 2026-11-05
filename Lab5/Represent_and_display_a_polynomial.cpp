#include <iostream>
using namespace std;
struct Node {
    int coeff;
    int exp;
    Node* next;
};
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Node* temp = new Node;
        cout << "Enter coefficient: ";
        cin >> temp->coeff;
        cout << "Enter exponent: ";
        cin >> temp->exp;
        temp->next = NULL;
        if (head == NULL)
            head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    cout << "Polynomial: ";
    Node* p = head;
    while (p != NULL) {
        cout << p->coeff << "x^" << p->exp;
        if (p->next != NULL)
            cout << " + ";

        p = p->next;
    }
    return 0;
}
