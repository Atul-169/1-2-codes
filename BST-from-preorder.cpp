#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) {
        key = val;
        left = nullptr;
        right = nullptr;
    }
};

// A Simple BST Insert
Node* insertBST(Node* root, int key);

// Constructs BST from the given Preorder Traversal
Node* construct(vector<int>& pre) {
    Node* root = nullptr;
  
    // One by one insert all keys from pre[]
    for (int key : pre) {
        root = insertBST(root, key);
    }
  
    return root;
}

// A Simple BST Insert
Node* insertBST(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);
    if (root->key > key)
        root->left = insertBST(root->left, key);
    else if (root->key < key)
        root->right = insertBST(root->right, key);
    return root;
}

// A function to print BST in inorder
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Driver code
int main() {
    vector<int> pre = {10, 5, 1, 7, 40, 50};
    Node* root = construct(pre);
    inorder(root);
    return 0;
}
