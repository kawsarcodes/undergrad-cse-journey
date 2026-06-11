/*
PROBLEM 01. Two Sum (Two Pointer Approach) 

Given a sorted array of integers, find two numbers such that they add up to a specific target number.

Sample input
5 9
2 3 4 5 7

Sample output
1 4
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    if (!(cin >> n >> target)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int left = 0, right = n - 1;
    while (left < right) {
        int current_sum = nums[left] + nums[right];
        if (current_sum == target) {
            cout << left + 1 << " " << right + 1 << "\n";
            return 0;
        } else if (current_sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return 0;
}