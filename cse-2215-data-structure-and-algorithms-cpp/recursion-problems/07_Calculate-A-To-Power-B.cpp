/*
Problem(7): Calculate A to the Power B.
Given a base A and an exponent B, calculate A raised to B using binary exponentiation strategy.
Example:
Input
2 5
Output
32
*/

#include <bits/stdc++.h>
using namespace std;

long long power(long long a, int b) {
    if (b == 0) return 1;
    long long half = power(a, b / 2);
    if (b % 2 == 0) {
        return half * half;
    } else {
        return a * half * half;
    }
}

int main() {
    long long a;
    int b;
    if (cin >> a >> b) {
        cout << power(a, b) << endl;
    }
    return 0;
}