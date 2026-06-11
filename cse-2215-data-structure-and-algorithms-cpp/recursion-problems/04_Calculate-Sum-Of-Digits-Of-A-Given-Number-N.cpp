/*
Problem(4): Calculate the Sum of Digits.
Given an integer N, compute the sum of its individual digits recursively.
Example:
Input
1234
Output
10
*/

#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int n;
    if (cin >> n) {
        cout << sumOfDigits(abs(n)) << endl;
    }
    return 0;
}