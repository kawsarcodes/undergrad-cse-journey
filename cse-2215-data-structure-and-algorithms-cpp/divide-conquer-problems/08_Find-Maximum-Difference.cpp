/*
Problem(8): Find Maximum Difference.
Given an array of integers, find the maximum difference between two elements such that the larger element appears after the smaller element.
Example:
Input
6
2 3 10 6 4 8
Output
8
*/

#include <bits/stdc++.h>
using namespace std;

struct SegmentData {
    int minVal;
    int maxVal;
    int maxDiff;
};

SegmentData getMaxDifference(const vector<int>& arr, int low, int high) {
    if (low == high) {
        return {arr[low], arr[low], 0};
    }
    
    int mid = low + (high - low) / 2;
    SegmentData leftSide = getMaxDifference(arr, low, mid);
    SegmentData rightSide = getMaxDifference(arr, mid + 1, high);
    
    int crossDiff = rightSide.maxVal - leftSide.minVal;
    int totalMaxDiff = max({leftSide.maxDiff, rightSide.maxDiff, crossDiff});
    int totalMinVal = min(leftSide.minVal, rightSide.minVal);
    int totalMaxVal = max(leftSide.maxVal, rightSide.maxVal);
    
    return {totalMinVal, totalMaxVal, totalMaxDiff};
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    SegmentData result = getMaxDifference(arr, 0, n - 1);
    cout << result.maxDiff << endl;
    return 0;
}