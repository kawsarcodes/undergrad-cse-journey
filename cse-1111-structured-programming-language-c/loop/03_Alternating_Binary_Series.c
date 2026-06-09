/*
Problem: Write a program (WAP) that will print following series upto Nth terms.
1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,  …….
Input 
4
Output
1, 0, 1, 0
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            printf("1");
        } else {
            printf("0");
        }
        if (i < n) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}