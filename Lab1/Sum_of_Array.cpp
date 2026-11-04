#include <iostream>
using namespace std;

void inputArray(int arr[3][3]){
    cout<<"Enter 9 elements for array:"<<endl;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3;j++){
            cin>>arr[i][j];
        }
    }
}

void displayArray(int arr[3][3]){
    cout<<"The array is:\n";
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int A[3][3];
    int B[3][3];
    int C[3][3];
    
    inputArray(A);
    inputArray(B);
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    
    displayArray(C);
    
    return 0;
}
