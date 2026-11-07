#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* top = NULL;
void push(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = top;
    top = temp;
    cout << "Element inserted\n";
}
void pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
    } else {
        Node* temp = top;
        cout << "Deleted element: " << top->data << endl;
        top = top->next;
        delete temp;
    }
}
void peek() {
    if (top == NULL)
        cout << "Stack is empty\n";
    else
        cout << "Top element: " << top->data << endl;
}
void display() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    Node* p = top;
    cout << "Stack elements:\n";
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}
int main() {
    int choice, value;
    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);
    while (top != NULL) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    return 0;
}
