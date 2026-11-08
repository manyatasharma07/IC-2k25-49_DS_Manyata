#include <iostream>
#include <climits>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        cout << "Duplicate values are not allowed\n";
    return root;
}
Node* findMin(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}
Node* findMax(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}
Node* deleteNode(Node* root, int value) {
    if (root == nullptr)
        return nullptr;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
bool search(Node* root, int value) {
    if (root == nullptr)
        return false;
    if (root->data == value)
        return true;
    if (value < root->data)
        return search(root->left, value);
    return search(root->right, value);
}
bool validateBST(Node* root, long long minValue, long long maxValue) {
    if (root == nullptr)
        return true;
    if (root->data <= minValue || root->data >= maxValue)
        return false;
    return validateBST(root->left, minValue, root->data) &&
           validateBST(root->right, root->data, maxValue);
}
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void deleteTree(Node* root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main() {
    Node* root = nullptr;
    int choice, value;
    do {
        cout << "\nBINARY SEARCH TREE\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Find Minimum\n";
        cout << "5. Find Maximum\n";
        cout << "6. Validate BST\n";
        cout << "7. Display Inorder\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                if (search(root, value)) {
                    root = deleteNode(root, value);
                    cout << "Node deleted successfully\n";
                } else {
                    cout << "Value not found\n";
                }
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value))
                    cout << "Value found\n";
                else
                    cout << "Value not found\n";
                break;
            case 4: {
                Node* minNode = findMin(root);
                if (minNode != nullptr)
                    cout << "Minimum value: " << minNode->data << '\n';
                else
                    cout << "Tree is empty\n";
                break;
            }
            case 5: {
                Node* maxNode = findMax(root);
                if (maxNode != nullptr)
                    cout << "Maximum value: " << maxNode->data << '\n';
                else
                    cout << "Tree is empty\n";
                break;
            }
            case 6:
                if (validateBST(root, LLONG_MIN, LLONG_MAX))
                    cout << "The tree is a valid BST\n";
                else
                    cout << "The tree is not a valid BST\n";
                break;
            case 7:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << '\n';
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 8);
    deleteTree(root);
    return 0;
}
