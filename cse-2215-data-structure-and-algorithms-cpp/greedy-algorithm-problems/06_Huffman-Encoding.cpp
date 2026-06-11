/*
PROBLEM 06. Huffman Encoding

Build a Huffman tree using a min-heap structure to compute variable length prefix binary codes 
for a given set of characters and frequencies.
*/

#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode {
    char data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};

void printCodes(MinHeapNode* root, string str) {
    if (!root) return;
    if (root->data != '$') {
        cout << root->data << ": " << str << "\n";
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < n; i++) {
        char ch;
        unsigned freq;
        cin >> ch >> freq;
        minHeap.push(new MinHeapNode(ch, freq));
    }

    while (minHeap.size() != 1) {
        MinHeapNode *left = minHeap.top(); minHeap.pop();
        MinHeapNode *right = minHeap.top(); minHeap.pop();

        MinHeapNode *top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
    return 0;
}