#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    int pos[100], neg[100];
    int p = 0, q = 0;
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
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            pos[p++] = arr[i];
        } else {
            neg[q++] = arr[i];
        }
    }
    cout << "Positive elements: ";
    for (int i = 0; i < p; i++) {
        cout << pos[i] << " ";
    }
    cout << "\nNegative elements: ";
    for (int i = 0; i < q; i++) {
        cout << neg[i] << " ";
    }
    cout << endl;
    return 0;
}
