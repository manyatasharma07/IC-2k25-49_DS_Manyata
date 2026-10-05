#include <iostream>
using namespace std;
int main() {
    int rows, cols;
    int choice;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
  
    int A[10][10], B[10][10], result[10][10];
    cout << "\nEnter elements of Matrix A:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A[i][j];
        }
    }
    cout << "\nEnter elements of Matrix B:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> B[i][j];
        }
    }
    cout << "\n1. Addition";
    cout << "\n2. Subtraction";
    cout << "\n3. Multiplication";
    cout << "\n4. Exit";
    cout << "\n\nEnter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[i][j] = A[i][j] + B[i][j];
                }
            }
            cout << "\nResult of Addition:" << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 2:
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[i][j] = A[i][j] - B[i][j];
                }
            }
            cout << "\nResult of Subtraction:" << endl;
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < cols; j++) {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 3:
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[i][j] = 0;
                    for (int k = 0; k < cols; k++){
                        result[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
            cout << "\nResult of Multiplication:" << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 4:
            cout << "\nProgram ended." << endl;
            break;
        default:
            cout << "\nInvalid choice." << endl;
    }
    return 0;
}
