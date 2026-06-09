/*
Problem: Program that will decide whether a year is leap year or not.
Input 
2014
Output
No
*/

#include <stdio.h>

int main() {
    int year;

    if (scanf("%d", &year) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}