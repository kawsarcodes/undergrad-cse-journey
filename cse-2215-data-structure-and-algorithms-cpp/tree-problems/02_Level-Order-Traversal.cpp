/*
PROBLEM 02. Level Order Traversal (Breadth First Search)

Given a binary tree, return the level order traversal of its nodes' values grouped by level.

       1
      / \
     2   3

Sample output
1 
2 3 
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    if (!root) return 0;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; i++) {
            Node* curr = q.front();
            q.pop();
            
            cout << curr->data << (i == level_size - 1 ? "" : " ");
            
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << "\n";
    }
    return 0;
}