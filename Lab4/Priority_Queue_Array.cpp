#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
class PriorityQueue {
    struct Item {
        int value;
        int priority;
    };
    Item arr[MAX_SIZE];
    int size;
public:
    PriorityQueue() {
        size = 0;
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == MAX_SIZE;
    }
    void enqueue(int value, int priority) {
        if (isFull()) {
            cout << "Priority Queue Overflow\n";
            return;
        }
        arr[size].value = value;
        arr[size].priority = priority;
        size++;
        cout << value << " inserted with priority " << priority << '\n';
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue Underflow\n";
            return;
        }
        int highest = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i].priority > arr[highest].priority)
                highest = i;
        }
        cout << "Deleted element: " << arr[highest].value
             << " (Priority: " << arr[highest].priority << ")\n";

        for (int i = highest; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }
    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty\n";
            return;
        }
        cout << "Value\tPriority\n";
        for (int i = 0; i < size; i++)
            cout << arr[i].value << "\t" << arr[i].priority << '\n';
    }
};
int main() {
    PriorityQueue pq;
    int choice, value, priority;

    do {
        cout << "\n1. Insert\n2. Delete Highest Priority\n";
        cout << "3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter priority (higher number = higher priority): ";
                cin >> priority;
                pq.enqueue(value, priority);
                break;
            case 2:
                pq.dequeue();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);
    return 0;
}
