/*
PROBLEM 03. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, find the area of the largest rectangle in the histogram.

Sample input
6
2 1 5 6 2 3

Sample output
10
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    stack<int> st;
    int max_area = 0;
    int i = 0;

    while (i < n) {
        if (st.empty() || heights[st.top()] <= heights[i]) {
            st.push(i++);
        } else {
            int tp = st.top();
            st.pop();
            int area = heights[tp] * (st.empty() ? i : i - st.top() - 1);
            max_area = max(max_area, area);
        }
    }

    while (!st.empty()) {
        int tp = st.top();
        st.pop();
        int area = heights[tp] * (st.empty() ? i : i - st.top() - 1);
        max_area = max(max_area, area);
    }

    cout << max_area << "\n";
    return 0;
}