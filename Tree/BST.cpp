#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int value) {
        val = value;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* insert(Node* root, int key) {
        if (root == nullptr)
            return new Node(key);
        if (key < root->val)
            root->left = insert(root->left, key);
        else
            root->right = insert(root->right, key);
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr)
            return root;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }

    void inorder(Node* root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    bool search(Node* root, int key) {
        if (root == nullptr)
            return false;
        if (key == root->val)
            return true;
        if (key < root->val)
            return search(root->left, key);
        else
            return search(root->right, key);
    }
};

int main() {
    BST tree;
    Node* root = nullptr;
    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 70);
    root = tree.insert(root, 20);
    root = tree.insert(root, 40);
    root = tree.insert(root, 60);
    root = tree.insert(root, 80);

    cout << "Inorder before deletion: ";
    tree.inorder(root);
    cout << endl;

    root = tree.deleteNode(root, 20);
    root = tree.deleteNode(root, 30);
    root = tree.deleteNode(root, 50);

    cout << "Inorder after deletion: ";
    tree.inorder(root);
    cout << endl;

    int key = 60;
    if (tree.search(root, key))
        cout << key << " found in BST" << endl;
    else
        cout << key << " not found in BST" << endl;

    return 0;
}