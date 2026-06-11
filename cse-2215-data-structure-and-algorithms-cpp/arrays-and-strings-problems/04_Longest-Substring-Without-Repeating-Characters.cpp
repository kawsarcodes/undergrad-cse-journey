/*
PROBLEM 04. Longest Substring Without Repeating Characters (Sliding Window)

Given a string s, find the length of the longest substring without repeating characters.

Sample input
abcabcbb

Sample output
3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;

    vector<int> char_map(256, -1);
    int max_len = 0, start = -1;

    for (int i = 0; i < s.length(); i++) {
        if (char_map[s[i]] > start) {
            start = char_map[s[i]];
        }
        char_map[s[i]] = i;
        max_len = max(max_len, i - start);
    }

    cout << max_len << "\n";
    return 0;
}