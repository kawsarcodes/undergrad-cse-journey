/*
Problem: WAP that will take n integer numbers into an array, and then print all the integers into reverse order (from the last valid index to index 0).
Input 
5
1  2  3  4  5
Output
5  4  3  2  1
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        printf("%d", arr[i]);
        if (i > 0) {
            printf("  ");
        }
    }
    printf("\n");

    return 0;
}