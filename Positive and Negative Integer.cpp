#include <iostream>
using namespace std;

void inputArray(int arr[6]) {
    cout << "Enter 6 elements: ";
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }
}

int main() {
    int arr[6];
    inputArray(arr);

    cout << "Positive elements: ";
    for (int i = 0; i < 6; i++) {
        if (arr[i] > 0){
            int positiveElements = arr[i];
            cout << positiveElements << " ";
        }
    }
    cout << endl;

    cout << "Negative elements: ";
    for (int i = 0; i < 6; i++) {    
        if (arr[i] < 0){
             int negativeElements = arr[i];
            cout << negativeElements << " ";
        }
    }
    cout << endl;

    return 0;


    return 0;
}
