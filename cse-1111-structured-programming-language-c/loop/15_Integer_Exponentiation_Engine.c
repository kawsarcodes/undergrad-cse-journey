/*
Problem: Write a program (WAP) that will find x^y (x to the power y) where x, y are positive integers.
Input 
5   2
Output
25
*/

#include <stdio.h>

int main() {
    int x, y;

    if (scanf("%d %d", &x, &y) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    long long result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }

    if (x == 0 && y > 0) {
        result = 0;
    }

    printf("%lld\n", result);

    return 0;
}