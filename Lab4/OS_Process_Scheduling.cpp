#include <iostream>
using namespace std;
const int MAX_PROCESSES = 100;
struct Process {
    int id;
    int burstTime;
    int priority;
};
void fcfsScheduling(Process processes[], int n) {
    int waitingTime[MAX_PROCESSES];
    int turnaroundTime[MAX_PROCESSES];
    int totalWaiting = 0;
    int totalTurnaround = 0;
    waitingTime[0] = 0;
    for (int i = 1; i < n; i++)
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
    cout << "\nFCFS Scheduling\n";
    cout << "Process\tBurst\tWaiting\tTurnaround\n";

    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
        totalWaiting += waitingTime[i];
        totalTurnaround += turnaroundTime[i];
        cout << "P" << processes[i].id << "\t"
             << processes[i].burstTime << "\t"
             << waitingTime[i] << "\t"
             << turnaroundTime[i] << '\n';
    }
    cout << "Average Waiting Time: "
         << static_cast<double>(totalWaiting) / n << '\n';
    cout << "Average Turnaround Time: "
         << static_cast<double>(totalTurnaround) / n << '\n';
}
void priorityScheduling(Process processes[], int n) {
    Process sorted[MAX_PROCESSES];

    for (int i = 0; i < n; i++)
        sorted[i] = processes[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sorted[j].priority < sorted[j + 1].priority) {
                Process temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    int waitingTime[MAX_PROCESSES];
    int totalWaiting = 0;
    int totalTurnaround = 0;
    waitingTime[0] = 0;

    for (int i = 1; i < n; i++)
        waitingTime[i] = waitingTime[i - 1] + sorted[i - 1].burstTime;

    cout << "\nPriority Scheduling\n";
    cout << "Higher priority number means higher priority.\n";
    cout << "Process\tPriority\tBurst\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; i++) {
        int turnaroundTime = waitingTime[i] + sorted[i].burstTime;
        totalWaiting += waitingTime[i];
        totalTurnaround += turnaroundTime;

        cout << "P" << sorted[i].id << "\t"
             << sorted[i].priority << "\t\t"
             << sorted[i].burstTime << "\t"
             << waitingTime[i] << "\t"
             << turnaroundTime << '\n';
    }
    cout << "Average Waiting Time: "
         << static_cast<double>(totalWaiting) / n << '\n';
    cout << "Average Turnaround Time: "
         << static_cast<double>(totalTurnaround) / n << '\n';
}
int main() {
  Process processes[MAX_PROCESSES];
    int n, choice;
    cout << "Enter number of processes (1-100): ";
    cin >> n;
    if (n < 1 || n > MAX_PROCESSES) {
        cout << "Invalid number of processes\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "\nEnter burst time for P" << i + 1 << ": ";
        cin >> processes[i].burstTime;
        cout << "Enter priority for P" << i + 1 << ": ";
        cin >> processes[i].priority;
        if (processes[i].burstTime <= 0) {
            cout << "Burst time must be positive\n";
            return 0;
        }
    }
    do {
        cout << "\n1. FCFS Scheduling\n";
        cout << "2. Priority Scheduling\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                fcfsScheduling(processes, n);
                break;
            case 2:
                priorityScheduling(processes, n);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 3);
    return 0;
}
