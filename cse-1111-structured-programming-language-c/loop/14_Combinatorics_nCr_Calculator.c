/*
Problem: Write a program (WAP) that will find nCr where n >= r; n and r are integers.
Input 
5   2
Output
10
*/

#include <stdio.h>

int main() {
    int n, r;

    if (scanf("%d %d", &n, &r) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    if (r > n || n < 0 || r < 0) {
        printf("0\n");
        return 0;
    }

    if (r > n - r) {
        r = n - r;
    }

    long long result = 1;
    for (int i = 1; i <= r; i++) {
        result *= (n - i + 1);
        result /= i;
    }

    printf("%lld\n", result);

    return 0;
}