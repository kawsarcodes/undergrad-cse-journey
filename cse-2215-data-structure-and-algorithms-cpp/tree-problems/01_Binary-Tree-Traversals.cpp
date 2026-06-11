/*
PROBLEM 01. Binary Tree Traversals (Inorder, Preorder, Postorder)

Given a binary tree, implement and display its nodes using depth first search traversal techniques.

       1
      / \
     2   3

Sample output
Preorder: 1 2 3 
Inorder: 2 1 3 
Postorder: 2 3 1 
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    // Manually constructing a basic tree for verification
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << "Preorder: "; preorder(root); cout << "\n";
    cout << "Inorder: "; inorder(root); cout << "\n";
    cout << "Postorder: "; postorder(root); cout << "\n";
    return 0;
}