#include <iostream>
using namespace std;
int main() {
    int arr[3];
    cout<<"Enter 3 elements for array:"<<endl;
    
    for(int i = 0; i<3; i++){
            cin>>arr[i];
    }
    
    cout<<"The array is:\n";
    
    for(int i=0;i<3;i++){
            cout<<arr[i]<<" ";
    }
    return 0;
}
