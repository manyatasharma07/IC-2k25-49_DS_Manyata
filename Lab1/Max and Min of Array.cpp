#include <iostream>
using namespace std;

void inputArray(int arr[3][3]) {
    cout << "Enter 9 elements of the Array: ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
}

int main() {
    int A[3][3];
    inputArray(A); 

    int max = A[0][0];          
    int min = A[0][0];              

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (A[i][j] > max) {
                max = A[i][j];
            }
            if (A[i][j] < min) {
                min = A[i][j];
            }
        }
    }

    cout << "Maximum element in the array: " << max << endl;
    cout << "Minimum element in the array: " << min << endl;

    return 0;
}
