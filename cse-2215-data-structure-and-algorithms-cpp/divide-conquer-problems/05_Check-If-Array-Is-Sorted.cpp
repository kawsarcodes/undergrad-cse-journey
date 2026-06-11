/*
Problem(5): Check if an Array is Sorted.
Given an array of integers, determine whether the array is sorted in ascending order using divide and conquer.
Example:
Input
5
1 3 4 6 8
Output
Sorted

Example:
Input
5
1 5 3 7 8
Output
Not Sorted
*/

#include <bits/stdc++.h>
using namespace std;

bool isSorted(const vector<int>& arr, int low, int high) {
    if (low >= high) {
        return true;
    }
    int mid = low + (high - low) / 2;
    
    bool leftSorted = isSorted(arr, low, mid);
    bool rightSorted = isSorted(arr, mid + 1, high);
    
    return leftSorted && rightSorted && (arr[mid] <= arr[mid + 1]);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (isSorted(arr, 0, n - 1)) {
        cout << "Sorted" << endl;
    } else {
        cout << "Not Sorted" << endl;
    }
    return 0;
}