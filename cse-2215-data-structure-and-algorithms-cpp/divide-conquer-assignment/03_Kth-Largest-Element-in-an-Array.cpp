/*
Q3:  Kth  Largest Element in an Array 

Given an integer array nums and an integer k, return the kth largest element in the array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element. 

Example 1: 
Input: nums = [3, 2, 1, 5, 6, 4], k = 2 
Output: 5 

Example 2: 
Input: nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4 
Output: 4 

Constraints: 
● 1 <= k <= nums.length <= 104 
● -104 <= nums[i] <= 104

*/


#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int left, int right) {
  int pivot = arr[right];
  int i = left - 1;

  for (int j = left; j < right; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[right]);
  return i + 1;
}

int quickSelect(vector<int> &nums, int left, int right, int k) {
  if (left == right) {
    return nums[left];
  }

  int pivotIndex = partition(nums, left, right);

  if (pivotIndex == k) {
    return nums[pivotIndex];
  } else if (pivotIndex > k) {
    return quickSelect(nums, left, pivotIndex - 1, k);
  } else {
    return quickSelect(nums, pivotIndex + 1, right, k);
  }
}

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n;

  vector<int> nums(n);
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int k;
  cout << "Enter k: ";
  cin >> k;

  int target = n - k;
  int result = quickSelect(nums, 0, n - 1, target);

  cout << result << endl;

  return 0;
}