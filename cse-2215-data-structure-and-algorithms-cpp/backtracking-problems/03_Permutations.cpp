/*
PROBLEM 03. Permutations

Given an array of distinct integers, return all possible permutations of the elements.

Sample input
3
1 2 3

Sample output
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 2 1 
3 1 2 
*/

#include <bits/stdc++.h>
using namespace std;

void generatePermutations(int index, vector<int>& nums) {
    if (index == nums.size()) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << (i == nums.size() - 1 ? "" : " ");
        }
        cout << "\n";
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        generatePermutations(index + 1, nums);
        swap(nums[index], nums[i]); // Backtrack
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());
    generatePermutations(0, nums);
    return 0;
}