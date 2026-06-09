/*
Problem: WAP that will first take n integers into an array A and then m integers into array B. Now swap all elements between array A and B. Finally show all elements of both array A and B.
Input 
8
7 8 1 3 2 6 4 3
3
3 2 1
Output
Array A : 3 2 1
Array B : 7 8 1 3 2 6 4 3
*/

#include <stdio.h>

int main() {
    int n, m;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    int a[200];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) return 1;
    }

    if (scanf("%d", &m) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    int b[200];
    for (int i = 0; i < m; i++) {
        if (scanf("%d", &b[i]) != 1) return 1;
    }

    int max_len = (n > m) ? n : m;
    for (int i = 0; i < max_len; i++) {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }

    int temp_len = n;
    n = m;
    m = temp_len;

    printf("Array A :");
    for (int i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");

    printf("Array B :");
    for (int i = 0; i < m; i++) {
        printf(" %d", b[i]);
    }
    printf("\n");

    return 0;
}