//(Q:10)-----------Find Peak Element with Binary Search-----------
/*
Problem: Given an array where elements increase and then decrease (a "mountain" array),
find the index of the peak element using binary search.
Example:
Input: arr = [1, 3, 8, 12, 4, 2]
Output: 3 (peak element 12 is at index 3)
*/

#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    vector<int> arr = {1, 3, 8, 12, 4, 2};
    
    int peakIndex = findPeakElement(arr);
    
    cout << "Peak Element found at index: " << peakIndex << endl;
    cout << "Value of Peak Element: " << arr[peakIndex] << endl;

    return 0;
}