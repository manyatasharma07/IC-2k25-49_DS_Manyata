#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
class Deque {
    int arr[MAX_SIZE];
    int front, rear, count;
public:
    Deque() {
        front = 0;
        rear = -1;
        count = 0;
    }
    bool isEmpty() {
        return count == 0;
    }
    bool isFull() {
        return count == MAX_SIZE;
    }
    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + MAX_SIZE) % MAX_SIZE;
        }
        arr[front] = value;
        count++;
        cout << value << " inserted at front\n";
    }
    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = value;
        count++;
        cout << value << " inserted at rear\n";
    }
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }
        cout << "Deleted from front: " << arr[front] << '\n';
        if (count == 1) {
            front = 0;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        count--;
    }
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }
        cout << "Deleted from rear: " << arr[rear] << '\n';
        if (count == 1) {
            front = 0;
            rear = -1;
        } else {
            rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
        }
        count--;
    }
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Deque: ";
        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % MAX_SIZE] << " ";

        cout << '\n';
    }
};
int main() {
    Deque dq;
    int choice, value;

    do {
        cout << "\n1. Insert Front\n2. Insert Rear\n";
        cout << "3. Delete Front\n4. Delete Rear\n";
        cout << "5. Display\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dq.insertFront(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                dq.insertRear(value);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                dq.display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 6);
    return 0;
}
