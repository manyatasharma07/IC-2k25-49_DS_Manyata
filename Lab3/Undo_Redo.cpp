#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Command {
public:
    virtual void execute(string& text) = 0;
    virtual void undo(string& text) = 0;
    virtual ~Command() {}
};
class InsertCommand : public Command {
    string value;
public:
    InsertCommand(string v) {
        value = v;
    }
    void execute(string& text) {
        text += value;
    }
    void undo(string& text) {
        text.erase(text.length() - value.length());
    }
};
int main() {
    string text = "";
    stack<Command*> undoStack;
    stack<Command*> redoStack;
    int choice;
    string input;
    do {
        cout << "\n\n1. Type Text";
        cout << "\n2. Undo";
        cout << "\n3. Redo";
        cout << "\n4. Display Text";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            cout << "Enter text: ";
            getline(cin, input);

            if (input.empty())
                continue;

            Command* cmd = new InsertCommand(input);
            cmd->execute(text);
            undoStack.push(cmd);
            while (!redoStack.empty()) {
                delete redoStack.top();
                redoStack.pop();
            }
            cout << "Text inserted";
        }
        else if (choice == 2) {
            if (undoStack.empty()) {
                cout << "Nothing to undo";
            } else {
                Command* cmd = undoStack.top();
                undoStack.pop();
                cmd->undo(text);
                redoStack.push(cmd);
                cout << "Undo successful";
            }
        }
        else if (choice == 3) {
            if (redoStack.empty()) {
                cout << "Nothing to redo";
            } else {
                Command* cmd = redoStack.top();
                redoStack.pop();
                cmd->execute(text);
                undoStack.push(cmd);
                cout << "Redo successful";
            }
        }
        else if (choice == 4) {
            cout << "Current Text: " << text;
        }
        else if (choice == 5) {
            cout << "Exiting...";
        }
        else {
            cout << "Invalid choice";
        }
    } while (choice != 5);
    while (!undoStack.empty()) {
        delete undoStack.top();
        undoStack.pop();
    }
    while (!redoStack.empty()) {
        delete redoStack.top();
        redoStack.pop();
    }
    return 0;
}
