/*
PROBLEM 04. Find Median from Data Stream

Implement a structure that continuously receives integers from a data stream and tracks the median using a max-heap and a min-heap.

Sample input
4
1 2 3 4

Sample output
1.0 1.5 2.0 2.5
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    priority_queue<int> max_heap_left; 
    priority_queue<int, vector<int>, greater<int>> min_heap_right;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        if (max_heap_left.empty() || val <= max_heap_left.top()) {
            max_heap_left.push(val);
        } else {
            min_heap_right.push(val);
        }

        if (max_heap_left.size() > min_heap_right.size() + 1) {
            min_heap_right.push(max_heap_left.top());
            max_heap_left.pop();
        } else if (min_heap_right.size() > max_heap_left.size()) {
            max_heap_left.push(min_heap_right.top());
            min_heap_right.pop();
        }

        double median;
        if (max_heap_left.size() == min_heap_right.size()) {
            median = (max_heap_left.top() + min_heap_right.top()) / 2.0;
        } else {
            median = max_heap_left.top();
        }

        cout << fixed << setprecision(1) << median << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}