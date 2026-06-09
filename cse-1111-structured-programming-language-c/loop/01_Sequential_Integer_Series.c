/*
Problem: Write a program (WAP) that will print following series upto Nth terms.
1,  2 ,  3 ,  4 ,  5 ,  6 , 7, 8, 9, 10, 11, 12, 13, 14,  …….
Input 
5
Output
1,  2 ,  3 ,  4 ,  5
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d", i);
        if (i < n) {
            printf(",  ");
        }
    }
    printf("\n");

    return 0;
}