/*
Problem(5): Count the Number of Digits.
Given an integer N, determine the total count of its digits recursively.
Example:
Input
54321
Output
5
*/

#include <bits/stdc++.h>
using namespace std;

int countDigits(int n) {
    if (n == 0) return 0;
    return 1 + countDigits(n / 10);
}

int main() {
    int n;
    if (cin >> n) {
        if (n == 0) cout << 1 << endl;
        else cout << countDigits(abs(n)) << endl;
    }
    return 0;
}