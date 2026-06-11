/*
Q4:  Reverse Pairs 

Given an integer array nums, return the number of reverse pairs in the array. 

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 
2 * nums[j]. 

Example 1: 
Input: nums = [1,3,2,3,1] 
Output: 2 

Example 2: 
Input: nums = [2,4,3,5,1] 
Output: 3 

Constraints: 
● 1 <= nums.length <= 5 * 104 
● -231 <= nums[i] <= 231 - 1

*/


#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++) {
    L[i] = nums[left + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = nums[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      nums[k] = L[i];
      i++;
    } else {
      nums[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    nums[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    nums[k] = R[j];
    j++;
    k++;
  }
}

int countPairs(vector<int> &nums, int left, int mid, int right) {
  int count = 0;
  int j = mid + 1;
  for (int i = left; i <= mid; i++) {
    while (j <= right) {
      int val1 = nums[i];
      int val2 = nums[j];

      if (val1 > val2 * 2) {
        j++;
      } else {
        break;
      }
    }
    count = count + (j - (mid + 1));
  }
  return count;
}

int reversePairs(vector<int> &nums, int left, int right) {
  if (left >= right) {
    return 0;
  }

  int mid = left + (right - left) / 2;

  int leftCount = reversePairs(nums, left, mid);
  int rightCount = reversePairs(nums, mid + 1, right);
  int midCount = countPairs(nums, left, mid, right);

  merge(nums, left, mid, right);

  return leftCount + rightCount + midCount;
}

int main() {
  int n;
  cin >> n;

  if (n <= 0) {
    return 0;
  }

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int result = reversePairs(nums, 0, n - 1);
  cout << result << endl;

  return 0;
}