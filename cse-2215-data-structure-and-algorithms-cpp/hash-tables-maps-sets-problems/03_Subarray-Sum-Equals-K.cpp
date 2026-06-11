/*
PROBLEM 03. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

Sample input
3 2
1 1 1

Sample output
2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> prefix_sums;
    prefix_sums[0] = 1;

    int current_sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        current_sum += nums[i];
        if (prefix_sums.count(current_sum - k)) {
            count += prefix_sums[current_sum - k];
        }
        prefix_sums[current_sum]++;
    }

    cout << count << "\n";
    return 0;
}