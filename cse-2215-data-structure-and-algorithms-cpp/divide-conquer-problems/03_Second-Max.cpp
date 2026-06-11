/*
Problem(3): Find the Second Maximum Element.
Given an array of integers, find the second largest element using divide and conquer.
Example:
Input
6
5 8 2 9 1 7
Output
8
*/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> getTwoMax(const vector<int>& arr, int low, int high) {
    if (low == high) {
        return {arr[low], INT_MIN};
    }
    if (low + 1 == high) {
        if (arr[low] > arr[high]) return {arr[low], arr[high]};
        return {arr[high], arr[low]};
    }
    
    int mid = low + (high - low) / 2;
    auto leftResult = getTwoMax(arr, low, mid);
    auto rightResult = getTwoMax(arr, mid + 1, high);
    
    vector<int> candidates = {leftResult.first, leftResult.second, rightResult.first, rightResult.second};
    sort(candidates.begin(), candidates.end(), greater<int>());
    
    return {candidates[0], candidates[1]};
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    auto result = getTwoMax(arr, 0, n - 1);
    cout << result.second << endl;
    return 0;
}