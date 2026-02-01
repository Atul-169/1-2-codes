Node* secondLargest(Node* root) {
    if(root == nullptr || (root->left == nullptr && root->right == nullptr))
        return nullptr; // not enough nodes

    Node* curr = root;
    Node* parent = nullptr;

    // Go to the largest
    while(curr->right != nullptr){
        parent = curr;
        curr = curr->right;
    }

    // Case 1: largest has left subtree
    if(curr->left != nullptr){
        curr = curr->left;
        while(curr->right != nullptr){
            curr = curr->right;
        }
        return curr;
    }

    // Case 2: largest has no left subtree
    return parent;
}
