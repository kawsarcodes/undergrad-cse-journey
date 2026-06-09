/*
Problem: WAP that will find the GCD (greatest common divisor) and LCM (least common multiple) of two positive integers.
Input 
5   7
Output
GCD: 1,LCM: 35
*/

#include <stdio.h>

int main() {
    int originalA, originalB;

    if (scanf("%d %d", &originalA, &originalB) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    int a = originalA;
    int b = originalB;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    int gcd = a;
    long long lcm = ((long long)originalA * originalB) / gcd;

    printf("GCD: %d,LCM: %lld\n", gcd, lcm);

    return 0;
}