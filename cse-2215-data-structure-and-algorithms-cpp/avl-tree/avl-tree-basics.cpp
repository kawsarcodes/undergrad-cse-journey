#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        int height;
        Node(int val){
            data = val;
            left = nullptr;
            right = nullptr;
            height = 1;
        }
};

class AVLTree{
    public:
        int getHeight(Node* n){
            if(n == nullptr) return 0;
            return n->height;
        }

        int getBalanceFactor(Node* n){
            if(n == nullptr) return 0;
            return getHeight(n->left) - getHeight(n->right);
        }

        Node* rightRotate(Node* y){
            Node* x = y->left;
            Node* T2 = x->right;
            x->right = y;
            y->left = T2;
            y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
            x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
            return x;
        }

        Node* leftRotate(Node* x){
            Node* y = x->right;
            Node* T2 = y->left;
            y->left = x;
            x->right = T2;
            x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
            y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
            return y;
        }

        Node* insert(Node* node, int data){
            if(node == nullptr) return new Node(data);
            if(data < node->data) node->left = insert(node->left, data);
            else if(data > node->data) node->right = insert(node->right, data);
            else return node;

            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
            int bf = getBalanceFactor(node);

            if(bf > 1 && data < node->left->data) return rightRotate(node);
            if(bf < -1 && data > node->right->data) return leftRotate(node);
            if(bf > 1 && data > node->left->data){
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
            if(bf < -1 && data < node->right->data){
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            return node;
        }

        void preOrder(Node* root){
            if(root != nullptr){
                cout << root->data << " ";
                preOrder(root->left);
                preOrder(root->right);
            }
        }
};

int main(){
    AVLTree tree;
    Node* root = nullptr;
    root = tree.insert(root, 10);
    root = tree.insert(root, 20);
    root = tree.insert(root, 30);
    cout << "Preorder transversal of AVL tree: ";
    tree.preOrder(root);
}