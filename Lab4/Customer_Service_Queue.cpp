#include <iostream>
#include <string>
using namespace std;
const int MAX_CUSTOMERS = 100;
class CustomerQueue {
    string customers[MAX_CUSTOMERS];
    int front, rear, count;
public:
    CustomerQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }
    bool isEmpty() {
        return count == 0;
    }
    bool isFull() {
        return count == MAX_CUSTOMERS;
    }
    void addCustomer(string name) {
        if (isFull()) {
            cout << "Customer queue is full\n";
            return;
        }
        rear = (rear + 1) % MAX_CUSTOMERS;
        customers[rear] = name;
        count++;
        cout << name << " added to the service queue\n";
    }
    void serveCustomer() {
        if (isEmpty()) {
            cout << "No customers waiting\n";
            return;
        }
        cout << "Now serving: " << customers[front] << '\n';
        front = (front + 1) % MAX_CUSTOMERS;
        count--;
        if (count == 0) {
            front = 0;
            rear = -1;
        }
    }
    void displayQueue() {
        if (isEmpty()) {
            cout << "No customers in the queue\n";
            return;
        }
        cout << "\nCustomers waiting:\n";
        for (int i = 0; i < count; i++)
            cout << i + 1 << ". "
                 << customers[(front + i) % MAX_CUSTOMERS] << '\n';
    }
};
int main() {
    CustomerQueue queue;
    int choice;
    string name;

    do {
        cout << "\nCUSTOMER SERVICE QUEUE\n";
        cout << "1. Add Customer\n";
        cout << "2. Serve Next Customer\n";
        cout << "3. Display Waiting Customers\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> ws;
                getline(cin, name);
                queue.addCustomer(name);
                break;
            case 2:
                queue.serveCustomer();
                break;
            case 3:
                queue.displayQueue();
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
