#include <iostream>
using namespace std;
int main() {
    int a[100], n, key;
    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter element to search: ";
    cin >> key;
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            cout << "Element found at position " << i + 1;
            found = 1;
            break;
        }
    }
    if (found == 0) {
        cout << "Element not found";
    }
    return 0;
}
