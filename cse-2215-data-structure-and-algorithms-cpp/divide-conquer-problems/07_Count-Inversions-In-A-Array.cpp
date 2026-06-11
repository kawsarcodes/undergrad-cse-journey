/*
Problem(7): Count Inversions in an Array.
An inversion is a pair of indices (i, j) such that i < j and arr[i] > arr[j].
Write a program to count the number of inversions in an array using a merge sort based divide and conquer approach.
Example:
Input
5
2 4 1 3 5
Output
3
*/

#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<int>& arr, int low, int mid, int high) {
    vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);
    
    int i = 0, j = 0, k = low;
    long long shifts = 0;
    
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            shifts += (left.size() - i); 
        }
    }
    
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
    
    return shifts;
}

long long countInversions(vector<int>& arr, int low, int high) {
    long long count = 0;
    if (low < high) {
        int mid = low + (high - low) / 2;
        count += countInversions(arr, low, mid);
        count += countInversions(arr, mid + 1, high);
        count += mergeAndCount(arr, low, mid, high);
    }
    return count;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << countInversions(arr, 0, n - 1) << endl;
    return 0;
}