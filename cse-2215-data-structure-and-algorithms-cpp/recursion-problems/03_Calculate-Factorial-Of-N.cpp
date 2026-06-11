/*
Problem(3): Calculate the Factorial of N.
Given an integer N, compute its factorial value using recursion.
Example:
Input
5
Output
120
*/

#include <bits/stdc++.h>
using namespace std;

long long getFactorial(int n) {
    if (n <= 1) return 1;
    return n * getFactorial(n - 1);
}

int main() {
    int n;
    if (cin >> n) {
        cout << getFactorial(n) << endl;
    }
    return 0;
}