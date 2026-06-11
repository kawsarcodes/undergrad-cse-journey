/*
Problem(6): Calculate the Nth Term of a Fibonacci Series.
Given an index N, find the Nth Fibonacci number (0-indexed base: F(0)=0, F(1)=1).
Example:
Input
6
Output
8
*/

#include <bits/stdc++.h>
using namespace std;

int getFibonacci(int n) {
    if (n <= 1) return n;
    return getFibonacci(n - 1) + getFibonacci(n - 2);
}

int main() {
    int n;
    if (cin >> n) {
        cout << getFibonacci(n) << endl;
    }
    return 0;
}