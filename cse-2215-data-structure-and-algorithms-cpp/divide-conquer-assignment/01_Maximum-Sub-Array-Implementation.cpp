/*
Q1: Maximum Sub-array Implementation 

Given an integer array nums, find the contiguous subarray (containing at least one 
number) which has the largest sum and return its sum. 
A subarray is a contiguous part of an array. 

Example 1: 
Input: nums = [-2, 1,-3, 4,-1, 2, 1,-5, 4] 
Output: 6 
Explanation: [4,-1, 2, 1] has the largest sum = 6. 
Example 2: 
Input: nums = [1] 
Output: 1 
Example 3: 
Input: nums = [5, 4,-1, 7, 8] 
Output: 23 

Constraints: 
● 1 <= nums.length <= 105 
● -104 <= nums[i] <= 104
*/


#include <bits/stdc++.h>
using namespace std;

int getMax(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int maxCrossingSum(vector<int> &nums, int low, int mid, int high) {
  int sum = 0;
  int leftSum = INT_MIN;

  for (int i = mid; i >= low; i--) {
    sum = sum + nums[i];
    if (sum > leftSum) {
      leftSum = sum;
    }
  }

  sum = 0;
  int rightSum = INT_MIN;
  for (int i = mid + 1; i <= high; i++) {
    sum = sum + nums[i];
    if (sum > rightSum) {
      rightSum = sum;
    }
  }

  return leftSum + rightSum;
}

int maxSubArraySum(vector<int> &nums, int low, int high) {
  if (low == high) {
    return nums[low];
  }

  int mid = (low + high) / 2;

  int leftMax = maxSubArraySum(nums, low, mid);
  int rightMax = maxSubArraySum(nums, mid + 1, high);
  int crossMax = maxCrossingSum(nums, low, mid, high);
  int tempMax = getMax(leftMax, rightMax);
  return getMax(tempMax, crossMax);
}

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n;

  if (n <= 0)
    return 0;

  vector<int> nums(n);
  cout << "Enter the numbers: " << endl;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int result = maxSubArraySum(nums, 0, n - 1);
  cout << "Max Sum: " << result << endl;

  return 0;
}