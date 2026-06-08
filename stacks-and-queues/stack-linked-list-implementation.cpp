/*
CORE IMPLEMENTATION: Linked List-Based Stack

A scratch implementation of a Stack data structure using a Singly Linked List 
to achieve dynamic allocation without automatic array resizing overhead.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListStack {
private:
    Node* topNode;
    int currentSize;

public:
    LinkedListStack() : topNode(nullptr), currentSize(0) {}

    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
        currentSize++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        currentSize--;
    }

    int top() {
        if (isEmpty()) return -1;
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    int size() {
        return currentSize;
    }
};

int main() {
    LinkedListStack st;
    st.push(100);
    st.push(200);
    
    cout << "Top element: " << st.top() << "\n";
    st.pop();
    cout << "Top element after pop: " << st.top() << "\n";
    
    return 0;
}