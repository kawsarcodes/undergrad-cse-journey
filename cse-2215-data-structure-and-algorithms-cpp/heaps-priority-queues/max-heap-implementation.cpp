/*
CORE IMPLEMENTATION: Binary Max Heap

A complete array-based implementation of a Max Binary Heap built from scratch 
supporting upward/downward heapify tasks for custom structure operations.
*/

#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        if (!heap.empty()) return heap[0];
        return -1;
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MaxHeap mh;
    mh.push(15);
    mh.push(40);
    mh.push(30);
    
    cout << "Max element: " << mh.top() << "\n"; // Outputs 40
    mh.pop();
    cout << "Max element after extraction: " << mh.top() << "\n"; // Outputs 30
    return 0;
}