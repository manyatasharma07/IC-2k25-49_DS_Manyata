#include <iostream>
using namespace std;
int main() {
    int a[100], n, k, choice;
    cout << "Enter array size: ";
    cin >> n;
    if (n <= 0 || n > 100) {
        cout << "Invalid size";
        return 0;
    }
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter number of rotations: ";
    cin >> k;
    if (k < 0) {
        cout << "Invalid rotation";
        return 0;
    }
    k = k % n;
    cout << "1. Left Rotation\n";
    cout << "2. Right Rotation\n";
    cout << "Enter choice: ";
    cin >> choice;
    if (choice == 1) {
        for (int j = 0; j < k; j++) {
            int first = a[0];
            for (int i = 0; i < n - 1; i++) {
                a[i] = a[i + 1];
            }
            a[n - 1] = first;
        }
    } 
    else if (choice == 2) {
        for (int j = 0; j < k; j++) {
            int last = a[n - 1];
            for (int i = n - 1; i > 0; i--) {                
              a[i] = a[i - 1];
            }
            a[0] = last;
        }
    } 
    else {
        cout << "Invalid choice";
        return 0;
    }
    cout << "Rotated array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
