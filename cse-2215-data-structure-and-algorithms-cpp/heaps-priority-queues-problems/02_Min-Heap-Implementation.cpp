/*
PROBLEM 02. Min Heap Implementation

Implement a standard Binary Min Heap from scratch supporting push, pop, and top operations.

Sample input
5
push 10
push 5
top
pop
top

Sample output
5
10
*/

#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
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
};

int main() {
    int q;
    if (!(cin >> q)) return 0;

    MinHeap mh;
    while (q--) {
        string op;
        cin >> op;
        if (op == "push") {
            int val;
            cin >> val;
            mh.push(val);
        } else if (op == "pop") {
            mh.pop();
        } else if (op == "top") {
            cout << mh.top() << "\n";
        }
    }
    return 0;
}