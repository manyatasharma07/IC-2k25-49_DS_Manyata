#include <iostream>
#include <vector>
using namespace std;

class ArrayOp{
    int p;
    int n;
    int pos;
 
    
public:
    ArrayOp(){
        cout<<"Enter value of p: ";
        cin>> p;
        int arr[p];
        for(int i = 0; i<p; i++){
        cin>> arr[i];
        }
    }
    
    void deleteEl(){
            int arr[p];
        cin>> n;
        cin>> pos;
        
    if(n<=p){
        for(int i = pos; i < n-1; i++ ){
        arr[i] = arr[i + 1];
        }
        p--;
      
    }
        else{
        cout<< "Invalid.\n";
        }
    }
    
    void display(){
        int arr[p];
        for(int i=0; i<p; i++) {
            cout<<arr[i];
        }
    }
};
 
int main() {
    ArrayOp a;
    a.deleteEl();
    a.display();
 
    
    return 0;
}

