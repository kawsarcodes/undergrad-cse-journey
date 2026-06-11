/*
PROBLEM 02. Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Sample input
6
100 4 200 1 3 2

Sample output
4
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    unordered_set<int> num_set;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        num_set.insert(val);
    }

    int longest_streak = 0;

    for (int num : num_set) {
        if (!num_set.count(num - 1)) {
            int current_num = num;
            int current_streak = 1;

            while (num_set.count(current_num + 1)) {
                current_num += 1;
                current_streak += 1;
            }

            longest_streak = max(longest_streak, current_streak);
        }
    }

    cout << longest_streak << "\n";
    return 0;
}