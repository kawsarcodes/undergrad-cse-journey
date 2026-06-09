/*
Problem: Write a program (WAP) that will reverse the digits of an input integer.
Input 
13579
Output
97531
*/

#include <stdio.h>

int main() {
    int num;

    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int sign = 1;
    if (num < 0) {
        sign = -1;
        num = -num;
    }

    int reversed = 0;
    while (num > 0) {
        reversed = (reversed * 10) + (num % 10);
        num /= 10;
    }

    printf("%d\n", reversed * sign);

    return 0;
}