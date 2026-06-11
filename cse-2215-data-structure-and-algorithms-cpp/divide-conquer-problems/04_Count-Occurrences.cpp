/*
Problem(4): Count Occurrences of a Number.
Given an array of integers and a number X, count how many times X appears using divide and conquer.
Example:
Input
7
1 3 2 3 5 3 7
X = 3
Output
3
*/

#include <bits/stdc++.h>
using namespace std;

int countOccurrences(const vector<int>& arr, int low, int high, int x) {
    if (low == high) {
        return (arr[low] == x) ? 1 : 0;
    }
    int mid = low + (high - low) / 2;
    return countOccurrences(arr, low, mid, x) + countOccurrences(arr, mid + 1, high, x);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    cout << countOccurrences(arr, 0, n - 1, x) << endl;
    return 0;
}