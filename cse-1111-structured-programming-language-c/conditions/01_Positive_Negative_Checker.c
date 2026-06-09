/*
Problem: Program that will decide whether a number is positive or not.
Input 
-11.11
Output
Negative
*/

#include <stdio.h>

int main() {
    float num;

    if (scanf("%f", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (num >= 0) {
        printf("Positive\n");
    } else {
        printf("Negative\n");
    }

    return 0;
}