#include <iostream>
using namespace std;

#define MAX 100
int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int value) {
    if (top1 + 1 == top2) {
        cout << "Stack Overflow" << endl;
        return;
    }
    arr[++top1] = value;
}

void push2(int value) {
    if (top1 + 1 == top2) {
        cout << "Stack Overflow" << endl;
        return;
    }
    arr[--top2] = value;
}

void pop1() {
    if (top1 == -1) {
        cout << "Stack 1 Underflow" << endl;
        return;
    }
    cout << "Deleted element: " << arr[top1--] << endl;
}

void pop2() {
    if (top2 == MAX) {
        cout << "Stack 2 Underflow" << endl;
        return;
    }
    cout << "Deleted element: " << arr[top2++] << endl;
}

void display1() {
    if (top1 == -1) {
        cout << "Stack 1 is empty" << endl;
        return;
    }

    cout << "Stack 1 elements: ";
    for (int i = top1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void display2() {
    if (top2 == MAX) {
        cout << "Stack 2 is empty" << endl;
        return;
    }

    cout << "Stack 2 elements: ";
    for (int i = top2; i < MAX; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int choice, value;
    do {
        cout << "\n1. Push in Stack 1";
        cout << "\n2. Push in Stack 2";
        cout << "\n3. Pop from Stack 1";
        cout << "\n4. Pop from Stack 2";
        cout << "\n5. Display Stack 1";
        cout << "\n6. Display Stack 2";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push1(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                push2(value);
                break;

            case 3:
                pop1();
                break;

            case 4:
                pop2();
                break;

            case 5:
                display1();
                break;

            case 6:
                display2();
                break;

            case 7:
                cout << "Exiting program" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 7);
    return 0;
}
