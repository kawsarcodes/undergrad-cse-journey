/*
Problem(2): Count Even Numbers in an Array.
Given an array of integers, count how many even numbers are present using divide and conquer.
Example:
Input
6
2 5 8 7 10 3
Output
3
*/

#include <bits/stdc++.h>
using namespace std;

int countEvens(const vector<int>& arr, int low, int high) {
    if (low == high) {
        return (arr[low] % 2 == 0) ? 1 : 0;
    }
    int mid = low + (high - low) / 2;
    return countEvens(arr, low, mid) + countEvens(arr, mid + 1, high);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << countEvens(arr, 0, n - 1) << endl;
    return 0;
}