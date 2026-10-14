#include <iostream>
using namespace std;

int main() {
    int arr[100], n, pos, value;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter element to insert: ";
    cin >> value;
    cout << "Enter position to insert: ";
    cin >> pos;
    if (n >= 100 || pos < 1 || pos > n + 1) {
        cout << "Invalid position or array is full" << endl;
        return 0;
    }

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    n++;
    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
