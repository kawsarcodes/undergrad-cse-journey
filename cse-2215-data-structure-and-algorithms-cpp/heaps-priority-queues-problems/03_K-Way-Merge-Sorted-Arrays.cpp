/*
PROBLEM 03. Merge K Sorted Arrays

Merge k sorted arrays into a single completely sorted array using a min heap.

Sample input
3
3 1 5 7
2 2 4
3 0 6 8

Sample output
0 1 2 4 5 6 7 8
*/

#include <bits/stdc++.h>
using namespace std;

struct Element {
    int val;
    int array_idx;
    int element_idx;

    bool operator>(const Element& other) const {
        return val > other.val;
    }
};

int main() {
    int k;
    if (!(cin >> k)) return 0;

    vector<vector<int>> arrays(k);
    priority_queue<Element, vector<Element>, greater<Element>> min_heap;

    for (int i = 0; i < k; i++) {
        int size;
        cin >> size;
        arrays[i].resize(size);
        for (int j = 0; j < size; j++) {
            cin >> arrays[i][j];
        }
        if (size > 0) {
            min_heap.push({arrays[i][0], i, 0});
        }
    }

    vector<int> result;
    while (!min_heap.empty()) {
        Element current = min_heap.top();
        min_heap.pop();

        result.push_back(current.val);

        int next_element_idx = current.element_idx + 1;
        if (next_element_idx < arrays[current.array_idx].size()) {
            min_heap.push({arrays[current.array_idx][next_element_idx], current.array_idx, next_element_idx});
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}