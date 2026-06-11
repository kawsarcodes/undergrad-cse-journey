/*
CORE IMPLEMENTATION: Circular Array-Based Queue

A scratch implementation of a FIFO Queue data structure utilizing a fixed circular 
array format to manage linear data movement with optimal index manipulation.
*/

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    int currentSize;

public:
    CircularQueue(int cap = 5) {
        capacity = cap;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = val;
        currentSize++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[frontIndex];
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == capacity;
    }

    int size() {
        return currentSize;
    }
};

int main() {
    CircularQueue q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Front element: " << q.peek() << "\n";
    q.dequeue();
    q.enqueue(40); // Works perfectly due to circular logic tracking
    
    cout << "New Front element: " << q.peek() << "\n";
    return 0;
}