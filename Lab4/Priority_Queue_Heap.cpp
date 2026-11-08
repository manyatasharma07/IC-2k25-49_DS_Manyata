#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
class PriorityQueue {
    struct Item {
        int value;
        int priority;
    };
    Item heap[MAX_SIZE];
    int size;
    void swapItems(int i, int j) {
        Item temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent].priority >= heap[index].priority)
                break;
            swapItems(parent, index);
            index = parent;
        }
    }
    void heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;
            if (left < size && heap[left].priority > heap[largest].priority)
                largest = left;
            if (right < size && heap[right].priority > heap[largest].priority)
                largest = right;
            if (largest == index)
                break;
            swapItems(index, largest);
            index = largest;
        }
    }
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
        heap[size].value = value;
        heap[size].priority = priority;
        heapifyUp(size);
        size++;
        cout << value << " inserted with priority " << priority << '\n';
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue Underflow\n";
            return;
        }
        cout << "Deleted element: " << heap[0].value
             << " (Priority: " << heap[0].priority << ")\n";
        heap[0] = heap[size - 1];
        size--;
        if (size > 0)
            heapifyDown(0);
    }
    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty\n";
            return;
        }
        cout << "Heap Array (Value, Priority):\n";
        for (int i = 0; i < size; i++)
            cout << "(" << heap[i].value << ", "
                 << heap[i].priority << ") ";
        cout << '\n';
    }
};
int main() {
    PriorityQueue pq;
    int choice, value, priority;

    do {
        cout << "\n1. Insert\n2. Delete Highest Priority\n";
        cout << "3. Display Heap\n4. Exit\n";
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
