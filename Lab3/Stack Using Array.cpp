#include <iostream>
using namespace std;

#define MAX 100
int stackArr[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    stackArr[++top] = value;
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << "Deleted element: " << stackArr[top--] << endl;
}

void display() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
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
                display();
                break;

            case 4:
                cout << "Exiting program" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 4);

    return 0;
}
