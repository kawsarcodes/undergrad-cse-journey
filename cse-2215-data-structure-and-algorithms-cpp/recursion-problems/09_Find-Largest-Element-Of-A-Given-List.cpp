/*
Problem(9): Find the Largest Element.
Given a list of integers, locate the largest value recursively.
Example:
Input
5
12 45 2 67 34
Output
67
*/

#include <bits/stdc++.h>
using namespace std;

int getLargest(const vector<int>& arr, int index) {
    if (index == arr.size() - 1) return arr[index];
    return max(arr[index], getLargest(arr, index + 1));
}

int main() {
    int n;
    if (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        if (n > 0) cout << getLargest(arr, 0) << endl;
    }
    return 0;
}