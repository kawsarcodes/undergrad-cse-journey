//(Q:7)-----------Find the Insert Position-----------
/*
Problem: Given a sorted array, return the index where a target value should be 
inserted to maintain the order. Use binary search.
Example:
Input: arr = [1, 3, 5, 6], target = 4
Output: 2
*/

#include<iostream>
#include<vector>
using namespace std;

int searchInsertPosition(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid; 
        } 
        else if (nums[mid] < target) {
            low = mid + 1; 
        } 
        else {
            high = mid - 1; 
        }
    }

    return low;
}

int main() {
    vector<int> arr = {1, 3, 5, 6};
    int target = 4;

    int index = searchInsertPosition(arr, target);

    cout << "Insert Position: " << index << endl;

    return 0;
}