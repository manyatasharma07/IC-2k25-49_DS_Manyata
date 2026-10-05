#include <iostream>
using namespace std;
int main() {
    int rows, cols;
    int matrix[10][10];
    int sparse[100][3];
    int count = 0;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter matrix elements: " << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] != 0) {
                sparse[count][0] = i;
                sparse[count][1] = j;
                sparse[count][2] = matrix[i][j];
                count++;
            }
        }
    }
    cout << "\nOriginal Matrix:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nSparse Matrix:" << endl;
    cout << "Row\tColumn\tValue" << endl;
    for (int i = 0; i < count; i++) {
        cout << sparse[i][0] << "\t"
             << sparse[i][1] << "\t"
             << sparse[i][2] << endl;
    }
    cout << "\nTotal non-zero elements: " << count << endl;
    return 0;
}
