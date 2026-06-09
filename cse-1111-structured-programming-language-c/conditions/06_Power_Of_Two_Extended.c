/*
Problem: Program that will read from the console a random number and check if it is a nonzero positive number. If the check is yes, it will determine if the number is a power of 2. If the check fails it will handle zero and negative validations.
Input 
-512
Output
Negative input is not valid
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n > 0) {
        if ((n & (n - 1)) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } else if (n == 0) {
        printf("Zero is not a valid input\n");
    } else {
        printf("Negative input is not valid\n");
    }

    return 0;
}