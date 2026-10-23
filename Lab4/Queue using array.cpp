#include <iostream>
using namespace std;
#define MAX 100

int queueArr[MAX];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow" << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queueArr[++rear] = value;
}
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow" << endl;
        return;
    }
    cout << "Deleted element: " << queueArr[front] << endl;
    front++;
    if (front > rear) {
        front = rear = -1;
    }
}
void display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}
int main() {
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
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
