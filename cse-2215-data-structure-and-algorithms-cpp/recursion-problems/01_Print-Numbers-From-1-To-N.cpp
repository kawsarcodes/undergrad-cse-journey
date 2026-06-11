/*
Problem(1): Print Numbers from 1 to N.
Given an integer N, print all numbers from 1 to N using recursion.
Example:
Input
5
Output
1 2 3 4 5 
*/

#include <bits/stdc++.h>
using namespace std;

void printTillN(int n) {
    if (n < 1) return;
    printTillN(n - 1);
    cout << n << " ";
}

int main() {
    int n;
    if (cin >> n) {
        printTillN(n);
        cout << endl;
    }
    return 0;
}