#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    bool leftThread;
    bool rightThread;
    Node(int value) {
        data = value;
        left = right = nullptr;
        leftThread = rightThread = true;
    }
};
Node* insertNode(Node* root, int value) {
    Node* parent = nullptr;
    Node* current = root;
    while (current) {
        if (value == current->data) {
            cout << "Duplicate value not allowed.\n";
            return root;
        }
        parent = current;
        if (value < current->data) {
            if (!current->leftThread)
                current = current->left;
            else
                break;
        } else {
            if (!current->rightThread)
                current = current->right;
            else
                break;
        }
    }
    Node* newNode = new Node(value);
    if (!parent)
        return newNode;
    if (value < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->leftThread = false;
        parent->left = newNode;
    } else {
        newNode->right = parent->right;
        newNode->left = parent;
        parent->rightThread = false;
        parent->right = newNode;
    }
    return root;
}
Node* leftMost(Node* node) {
    if (!node)
        return nullptr;
    while (!node->leftThread)
        node = node->left;
    return node;
}
void inorder(Node* root) {
    Node* current = leftMost(root);
    while (current) {
        cout << current->data << " ";
        if (current->rightThread)
            current = current->right;
        else
            current = leftMost(current->right);
    }
}
void destroyTree(Node* root) {
    if (!root)
        return;
    if (!root->leftThread)
        destroyTree(root->left);
    if (!root->rightThread)
        destroyTree(root->right);
    delete root;
}
int main() {
    Node* root = nullptr;
    int choice, value;
    do {
        cout << "\n1. Insert\n2. Inorder Traversal\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insertNode(root, value);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 3);
    destroyTree(root);
    return 0;
}
