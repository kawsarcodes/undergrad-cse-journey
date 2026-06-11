/*
PROBLEM 01. Top K Frequent Elements

Given an integer array and an integer k, return the k most frequent elements.

Sample input
6 2
1 1 1 2 2 3

Sample output
1 2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    unordered_map<int, int> counts;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        counts[val]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    for (auto const& [num, count] : counts) {
        min_heap.push({count, num});
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    vector<int> result;
    while (!min_heap.empty()) {
        result.push_back(min_heap.top().second);
        min_heap.pop();
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}