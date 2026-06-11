/*
CORE IMPLEMENTATION: Dynamic Array-Based Stack

A scratch implementation of a Stack data structure using a dynamically 
resizing array, supporting standard LIFO operations.
*/

#include <iostream>
using namespace std;

class ArrayStack {
private:
    int* arr;
    int capacity;
    int topIndex;

    void resize(int newCapacity) {
        int* temp = new int[newCapacity];
        for (int i = 0; i <= topIndex; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = newCapacity;
    }

public:
    ArrayStack() {
        capacity = 2;
        arr = new int[capacity];
        topIndex = -1;
    }

    ~ArrayStack() {
        delete[] arr;
    }

    void push(int val) {
        if (topIndex == capacity - 1) {
            resize(capacity * 2);
        }
        arr[++topIndex] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
        if (topIndex >= 0 && topIndex < capacity / 4) {
            resize(capacity / 2);
        }
    }

    int top() {
        if (isEmpty()) return -1;
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    int size() {
        return topIndex + 1;
    }
};

int main() {
    ArrayStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    
    cout << "Top element: " << st.top() << "\n";
    cout << "Stack size: " << st.size() << "\n";
    
    st.pop();
    cout << "Top element after pop: " << st.top() << "\n";
    
    return 0;
}