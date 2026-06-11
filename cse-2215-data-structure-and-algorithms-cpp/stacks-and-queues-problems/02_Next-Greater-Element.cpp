/*
PROBLEM 02. Next Greater Element

Given an array, find the next greater element for every element. The next greater element for an element x is the first greater element on the right side of x in the array.

Sample input
4
4 5 2 25

Sample output
5 25 25 -1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nge[i] = st.top();
        }
        st.push(nums[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << nge[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}