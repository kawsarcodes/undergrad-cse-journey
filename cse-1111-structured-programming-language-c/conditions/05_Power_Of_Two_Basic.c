/*
Problem: Program that will read from the console a random positive nonzero number and determine if it is a power of 2.
Input 
512
Output
Yes
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n > 0 && (n & (n - 1)) == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}