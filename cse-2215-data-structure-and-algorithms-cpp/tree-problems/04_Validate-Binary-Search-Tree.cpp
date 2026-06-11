/*
PROBLEM 04. Validate Binary Search Tree (BST)

Given the root of a binary tree, determine if it is a valid binary search tree.
A valid BST requires all left subtree nodes to be strictly less than the parent node,
and all right subtree nodes to be strictly greater.

       2
      / \
     1   3

Sample output
1
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool validate(Node* root, long long min_val, long long max_val) {
    if (!root) return true;
    if (root->data <= min_val || root->data >= max_val) return false;
    
    return validate(root->left, min_val, root->data) && 
           validate(root->right, root->data, max_val);
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    // Using long long limits to safely handle integer boundaries
    cout << validate(root, LLONG_MIN, LLONG_MAX) << "\n";
    return 0;
}