/*
Problem: WAP that will take n integers into an array A, and then copy all numbers in reverse order from array A to another array B. Finally show all elements of both array A and B.
Input 
3
3 2 1
Output
Array A : 3 2 1
Array B : 1 2 3
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int a[n];
    int b[n];

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        b[n - 1 - i] = a[i];
    }

    printf("Array A :");
    for (int i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");

    printf("Array B :");
    for (int i = 0; i < n; i++) {
        printf(" %d", b[i]);
    }
    printf("\n");

    return 0;
}