/*
Problem(1): Find the sum of an Array.
Given an array of integers, compute the sum of all elements using divide and conquer.
Example: 
Input
5
1 2 3 4 5
Output
15
*/

#include <bits/stdc++.h>
using namespace std;

int getSum(const vector<int>& arr, int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = low + (high - low) / 2;
    int leftSum = getSum(arr, low, mid);
    int rightSum = getSum(arr, mid + 1, high);
    return leftSum + rightSum;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << getSum(arr, 0, n - 1) << endl;
    return 0;
}