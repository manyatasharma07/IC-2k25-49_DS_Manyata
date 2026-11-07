#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;
int main() {
    stack<int> s;
    string expression, token;

    cout << "Enter postfix expression: ";
    getline(cin, expression);
    stringstream ss(expression);
    while (ss >> token) {
        if (token == "+" || token == "-" ||
            token == "*" || token == "/") {
          
          if (s.size() < 2) {
                cout << "Invalid expression";
                return 0;
            }
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            if (token == "+")
                s.push(a + b);
            else if (token == "-")
                s.push(a - b);
            else if (token == "*")
                s.push(a * b);
            else {
                if (b == 0) {
                    cout << "Division by zero";
                    return 0;
                }
                s.push(a / b);
            }
        } else {
            stringstream value(token);
            int num;
            char extra;
            if (!(value >> num) || (value >> extra)) {      
                cout << "Invalid expression";
                return 0;
            }
            s.push(num);
        }
    }
    if (s.size() != 1) {
        cout << "Invalid expression";
        return 0;
    }
    cout << "Result: " << s.top();
    return 0;
}
