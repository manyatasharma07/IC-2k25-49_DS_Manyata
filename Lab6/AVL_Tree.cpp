#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        height = 1;
        left = right = nullptr;
    }
};
int getHeight(Node* node) {
    return node ? node->height : 0;
}
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}
void updateHeight(Node* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* temp = x->right;
    x->right = y;
    y->left = temp;
    updateHeight(y);
    updateHeight(x);
    return x;
}
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* temp = y->left;
    y->left = x;
    x->right = temp;
    updateHeight(x);
    updateHeight(y);
    return y;
}
Node* insertNode(Node* root, int value) {
    if (!root)
        return new Node(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    else
        return root;
    updateHeight(root);
    int balance = getBalance(root);
    if (balance > 1 && value < root->left->data)
        return rightRotate(root);
    if (balance < -1 && value > root->right->data)
        return leftRotate(root);
    if (balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
Node* findMin(Node* root) {
    while (root->left)
        root = root->left;
    return root;
}
Node* deleteNode(Node* root, int value) {
    if (!root)
        return root;
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                delete root;
                return nullptr;
            }
            *root = *temp;
            delete temp;
        }
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    updateHeight(root);
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
bool searchNode(Node* root, int value) {
    if (!root)
        return false;
    if (root->data == value)
        return true;
    if (value < root->data)
        return searchNode(root->left, value);
    return searchNode(root->right, value);
}
void inorder(Node* root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void deleteTree(Node* root) {
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main() {
    Node* root = nullptr;
    int choice, value;
    do {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display Inorder\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insertNode(root, value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                if (searchNode(root, value)) {
                    root = deleteNode(root, value);
                    cout << "Value deleted.\n";
                } else {
                    cout << "Value not found.\n";
                }
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << (searchNode(root, value) ? "Found\n" : "Not Found\n");
                break;
            case 4:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;
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
