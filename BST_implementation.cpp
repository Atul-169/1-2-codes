#ifndef LISTBST_H
#define LISTBST_H

#include "BST.hpp"
#include <iostream>
#include <stdexcept>
#include <queue>
using namespace std;

/**
 * Binary Search Tree implementation using linked list structure
 * 
 * @tparam Key - The type of keys stored in the BST
 * @tparam Value - The type of values associated with keys
 */
template <typename Key, typename Value>
class ListBST : public BST<Key, Value> {
private:
    /**
     * Node class for the binary search tree
     */
    class Node {
    public:
        Key key;
        Value value;
        Node* left;
        Node* right;
        
        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    size_t node_count;
    
    // TODO: Implement private helper functions as needed
    // Start your private helper functions here
    void inorder(Node* node)const{
        if(node==nullptr) return;
        inorder(node->left);
        cout<<"("<<node->key<<":"<<node->value<<") ";
        inorder(node->right);
    }
    void preorder(Node* node)const{
        if(node==nullptr) return ;
        cout<<"("<<node->key<<":"<<node->value<<") ";
        preorder(node->left);
        preorder(node->right);

    }
    void postorder(Node* node)const{
        if(node==nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout<<"("<<node->key<<":"<<node->value<<") ";
    }
    void level_order(Node* root) const{
        if(root==nullptr) return ;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            cout<<"("<<curr->key<<":"<<curr->value<<") ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);

        }

    }
    void default_print(Node* rt)const{
    if(rt == nullptr){
        cout<<"()";
        return;
    }
    
    cout<<"("<<rt->key <<":"<<rt->value;
    if(rt->right != nullptr){
        cout<<" ";
        if(rt->left)
            default_print(rt->left);
        else
            cout<<"()";

        cout <<" ";
        default_print(rt->right);
    }
    else if(rt->left != nullptr){
        cout<<" ";
        default_print(rt->left);
    }

    cout<<")";
    }

    Node* rmv(Node* rt,Key key){
        if(rt==nullptr) return rt;
        if(key>rt->key){
            rt->right=rmv(rt->right,key);

        }
        else if(key<rt->key){
            rt->left=rmv(rt->left,key);
        }
        else{
            if(rt->left==nullptr){
                Node* temp=rt->right;
                delete rt;
                node_count--;
                return temp;
            }
            else if(rt->right==nullptr){
                Node* temp=rt->left;
                delete rt;
                node_count--;
                return temp;

            }
            else{
                Node* succ=rt->right;
                while(succ->left!=nullptr){
                    succ=succ->left;
                }
                rt->key=succ->key;
                rt->value=succ->value;
                rt->right=rmv(rt->right,succ->key);
            }
        }
        return rt;
    }
    void recursive_clear(Node* root){
        if(root==nullptr) return ;
        recursive_clear(root->left);
        recursive_clear(root->right);
        delete root;
    }
    int height(Node* root) const {
        int h=0;
        if(root==nullptr) return h;
        int left_height=height(root->left);
        int right_height=height(root->right);
        h=1+max(left_height,right_height);
        return h;


    }
    // End your private helper functions here

public:
    /**
     * Constructor
     */
    ListBST() : root(nullptr), node_count(0) {}
    
    /**
     * Destructor
     */
    ~ListBST() {
        // TODO: Implement destructor to free memory
        clear();
        
    }
    
    /**
     * Insert a key-value pair into the BST
     */
    bool insert(Key key, Value value) override {
        // TODO: Implement insertion logic
        Node* newNode=new Node(key,value);
        if(root==nullptr){
            root=newNode;
            node_count++;
            return true;
        }
        Node* curr=root;
        Node* parent=nullptr;
        while(curr!=nullptr){
             parent=curr;
            if(key<curr->key){
                curr=curr->left;
            }
            else if(key>curr->key){
                curr=curr->right;
            }
            else{
                delete newNode;
                return false;
            }

        }
        if(key<parent->key){
            parent->left=newNode;
        }
        else {
            parent->right=newNode;
        }
        node_count++;
        return true;
    }

    
    
    /**
     * Remove a key-value pair from the BST
     */
    bool remove(Key key) override {
        // TODO: Implement removal logic
        if(!find(key)) return false;
        root=rmv(root,key);
        return true;
        
    }
    
    /**
     * Find if a key exists in the BST
     */
    bool find(Key key) const override {
        // TODO: Implement find logic
        Node* curr=root;
        while(curr!=nullptr){
            if(curr->key==key){
                return true;

            }
            else if(curr->key<key){
                curr=curr->right;
            }
            else {
                curr=curr->left;

            }

        }
        return false;

    }

    /**
     * Find a value associated with a given key
     */
    Value get(Key key) const override {
        // TODO: Implement get logic
        Node* curr=root;
        while(curr!=nullptr){
            if(curr->key==key){
                return curr->value;
            }
            else if(curr->key<key){
                curr=curr->right;

            }
            else{
                curr=curr->left;

            }
        }
        throw runtime_error("Key not found");
        
        
    }

    /**
     * Update the value associated with a given key
     */
    void update(Key key, Value value) override {
        // TODO: Implement update logic
        Node* curr=root;
        while(curr!=nullptr){
            if(curr->key==key){
                
                curr->value=value;
                return ;
            }
            else if(curr->key<key){
                curr=curr->right;
            }
            else {
                curr=curr->left;

            }

        }
        throw out_of_range("Key not found");
        

    }

    /**
     * Clear all elements from the BST
     */
    void clear() override {
        // TODO: Implement clear logic
       recursive_clear(root);
       root=nullptr;
       node_count=0;
       
    
    }
    
    /**
     * Get the number of keys in the BST
     */
    size_t size() const override {
        // TODO: Implement size logic
        return node_count;

    }
    
    /**
     * Check if the BST is empty
     */
    bool empty() const override {
        // TODO: Implement empty check logic
        return node_count==0;

    }
    
    /**
     * Find the minimum key in the BST
     */
    Key find_min() const override {
        // TODO: Implement find_min logic
        if(root==nullptr){
            
            throw out_of_range("BST is empty");
        }
        Node* curr=root;
        while(curr!=nullptr && curr->left!=nullptr){
            curr=curr->left;
        }
        return curr->key;

    }
    
    /**
     * Find the maximum key in the BST
     */
    Key find_max() const override {
        // TODO: Implement find_max logic
        if(root==nullptr){
            throw out_of_range("BST is empty");
        }
        Node* curr=root;
        while(curr!=nullptr && curr->right!=nullptr){
            curr=curr->right;
        }
        return curr->key;
    }

    /**
     * Print the BST using specified traversal method
     */

    void print(char traversal_type = 'D') const override {
        // TODO: Implement print logic
        if(traversal_type=='D'){
            cout<<" BST (Default): ";
            default_print(root);
        }
        else if(traversal_type=='I'){
            inorder(root);
        }
        else if(traversal_type=='P'){
            preorder(root);

        }
        else if(traversal_type=='O' ){
            postorder(root);
        }
        else if(traversal_type=='L' || traversal_type=='l'){
            cout<<"level-order: ";
            level_order(root);
            cout<<endl;


        }
    }
    int getHeight() const{
        return height(root);
    }
    
    
};

#endif // LISTBST_H
