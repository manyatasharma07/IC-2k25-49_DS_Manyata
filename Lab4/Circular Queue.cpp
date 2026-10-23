#include <iostream>
using namespace std;
#define MAX 5

int queueArr[MAX];
int front = -1;
int rear = -1;
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        cout << "Queue Overflow" << endl;
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queueArr[rear] = value;
}
void dequeue() {
    if (front == -1) {
        cout << "Queue Underflow" << endl;
        return;
    }
    cout << "Deleted element: " << queueArr[front] << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}
void display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
   cout << "Queue elements: ";
    int i = front;

    while (true) {
        cout << queueArr[i] << " ";
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
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
