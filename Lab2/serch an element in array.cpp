#include <iostream>
using namespace std;

int main() {
    int arr[100], n, key;
    bool found = false;
    cout << "Enter number of elements: ";
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Invalid array size" << endl;
        return 0;
    }
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Element not found" << endl;
    }
    return 0;
}
