/*
Problem: Program that will decide whether a number is even or odd.
Input 
-77
Output
Odd
*/

#include <stdio.h>

int main() {
    int num;

    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (num % 2 == 0) {
        printf("Even\n");
    } else {
        printf("Odd\n");
    }

    return 0;
}