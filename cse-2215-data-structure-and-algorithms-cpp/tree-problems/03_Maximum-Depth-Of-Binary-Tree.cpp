/*
PROBLEM 03. Maximum Depth of Binary Tree

Find the maximum depth (height) of a binary tree, which is the number of nodes along the 
longest path from the root node down to the farthest leaf node.

       1
      / \
     2   3
    /
   4

Sample output
3
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int maxDepth(Node* root) {
    if (!root) return 0;
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return 1 + max(left_depth, right_depth);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << maxDepth(root) << "\n";
    return 0;
}