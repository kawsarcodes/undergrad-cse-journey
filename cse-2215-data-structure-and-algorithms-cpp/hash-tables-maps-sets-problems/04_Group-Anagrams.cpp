/*
PROBLEM 04. Group Anagrams

Given an array of strings, group the anagrams together.

Sample input
6
eat tea tan ate nat bat

Sample output
bat 
eat tea ate 
tan nat 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    unordered_map<string, vector<string>> groups;
    for (const string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }

    for (auto const& [key, group] : groups) {
        for (int i = 0; i < group.size(); i++) {
            cout << group[i] << (i == group.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}