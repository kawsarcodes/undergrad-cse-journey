/*
Problem: Program that will take two numbers X & Y as inputs and decide whether X is greater than/less than/equal to Y.
Input 
5   -10
Output
5 is greater than -10
*/

#include <stdio.h>

int main() {
    int x, y;

    if (scanf("%d %d", &x, &y) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    if (x > y) {
        printf("%d is greater than %d\n", x, y);
    } else if (x < y) {
        printf("%d is less than %d\n", x, y);
    } else {
        printf("%d is equal to %d\n", x, y);
    }

    return 0;
}