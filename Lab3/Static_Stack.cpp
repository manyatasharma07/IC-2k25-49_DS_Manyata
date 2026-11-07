#include <iostream>
using namespace std;
#define MAX 100
int stackArr[MAX];
int top = -1;
void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
    } else {
        stackArr[++top] = value;
        cout << "Element inserted\n";
    }
}
void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
    } else {
        cout << "Deleted element: " << stackArr[top--] << endl;
    }
}
void peek() {
    if (top == -1)
        cout << "Stack is empty\n";
    else
        cout << "Top element: " << stackArr[top] << endl;
}
void display() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements:\n";
    for (int i = top; i >= 0; i--)
        cout << stackArr[i] << endl;
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
    return 0;
}
