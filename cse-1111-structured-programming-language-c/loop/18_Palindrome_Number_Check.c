/*
Problem: WAP that will determine whether an integer is palindrome number or not.
Input 
12321
Output
Yes
*/

#include <stdio.h>

int main() {
    int originalNum;

    if (scanf("%d", &originalNum) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int num = originalNum;
    int reversed = 0;

    while (num > 0) {
        reversed = (reversed * 10) + (num % 10);
        num /= 10;
    }

    if (originalNum == reversed) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}