#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node {
    string name;
    bool isFile;
    vector<Node*> children;
    Node(string value, bool file) {
        name = value;
        isFile = file;
    }
};
Node* findFolder(Node* root, string name) {
    if (!root)
        return nullptr;
    if (root->name == name && !root->isFile)
        return root;
    for (Node* child : root->children) {
        Node* result = findFolder(child, name);
        if (result)
            return result;
    }
    return nullptr;
}
Node* searchNode(Node* root, string name) {
    if (!root)
        return nullptr;
    if (root->name == name)
        return root;
    for (Node* child : root->children) {
        Node* result = searchNode(child, name);
        if (result)
            return result;
    }
    return nullptr;
}
void createItem(Node* root, string parentName, string itemName, bool isFile) {
    Node* parent = findFolder(root, parentName);
    if (!parent) {
        cout << "Parent folder not found.\n";
        return;
    }
    for (Node* child : parent->children) {
        if (child->name == itemName) {
            cout << "An item with this name already exists here.\n";
            return;
        }
    }
    parent->children.push_back(new Node(itemName, isFile));
    cout << (isFile ? "File" : "Folder") << " created successfully.\n";
}
void displayTree(Node* root, int level = 0) {
    if (!root)
        return;
    for (int i = 0; i < level; i++)
        cout << "    ";
    cout << (root->isFile ? "[File] " : "[Folder] ") << root->name << endl;
    for (Node* child : root->children)
        displayTree(child, level + 1);
}
void deleteTree(Node* root) {
    if (!root)
        return;
    for (Node* child : root->children)
        deleteTree(child);
    delete root;
}
int main() {
    Node* root = new Node("Root", false);
    int choice;
    string parentName, itemName;
    do {
        cout << "\n1. Create Folder\n2. Create File\n3. Display File System\n4. Search Item\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter parent folder name: ";
                cin >> parentName;
                cout << "Enter new folder name: ";
                cin >> itemName;
                createItem(root, parentName, itemName, false);
                break;
            case 2:
                cout << "Enter parent folder name: ";
                cin >> parentName;
                cout << "Enter file name: ";
                cin >> itemName;
                createItem(root, parentName, itemName, true);
                break;
            case 3:
                cout << "\nFile System Structure:\n";
                displayTree(root);
                break;
            case 4: {
                cout << "Enter item name to search: ";
                cin >> itemName;
                Node* result = searchNode(root, itemName);
                if (result)
                    cout << (result->isFile ? "File" : "Folder") << " found: " << result->name << endl;
                else
                    cout << "Item not found.\n";
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);
    deleteTree(root);
    return 0;
}
