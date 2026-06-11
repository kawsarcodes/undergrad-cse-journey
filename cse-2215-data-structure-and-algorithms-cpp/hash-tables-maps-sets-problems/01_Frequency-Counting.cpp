/*
PROBLEM 01. Frequency Counting

Count the frequency of each element in an array using a hash map.

Sample input
6
2 2 3 4 4 4

Sample output
2 2
3 1
4 3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        freq[val]++;
    }

    for (auto const& [key, val] : freq) {
        cout << key << " " << val << "\n";
    }
    return 0;
}