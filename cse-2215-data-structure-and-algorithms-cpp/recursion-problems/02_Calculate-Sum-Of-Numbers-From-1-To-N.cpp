/*
Problem(2): Calculate the Sum of Numbers from 1 to N.
Given an integer N, find the sum of all integers from 1 to N using recursion.
Example:
Input
5
Output
15
*/

#include <bits/stdc++.h>
using namespace std;

int getSum(int n) {
    if (n <= 1) return n;
    return n + getSum(n - 1);
}

int main() {
    int n;
    if (cin >> n) {
        cout << getSum(n) << endl;
    }
    return 0;
}