#include <iostream>
#include <stack>
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
Node* createTree() {
    int value;
    cout << "Enter node value (-1 for no node): ";
    cin >> value;
    if (value == -1)
        return nullptr;
    Node* root = new Node(value);
    cout << "Enter left child of " << value << '\n';
    root->left = createTree();
    cout << "Enter right child of " << value << '\n';
    root->right = createTree();
    return root;
}
void inorder(Node* root) {
    stack<Node*> s;
    Node* current = root;
    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
}
void preorder(Node* root) {
    if (root == nullptr)
        return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        cout << current->data << " ";
        if (current->right != nullptr)
            s.push(current->right);
        if (current->left != nullptr)
            s.push(current->left);
    }
}
void postorder(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);
        if (current->left != nullptr)
            s1.push(current->left);
        if (current->right != nullptr)
            s1.push(current->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}
void deleteTree(Node* root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main() {
    cout << "Create Binary Tree\n";
    Node* root = createTree();
    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << '\n';
    deleteTree(root);
    return 0;
} 
