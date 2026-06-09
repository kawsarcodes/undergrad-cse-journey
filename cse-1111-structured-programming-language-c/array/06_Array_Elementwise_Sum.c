/*
Problem: Wap that will take n integer numbers in an array, n different integer numbers in a second array and put the sum of the same indexed numbers from the two arrays in a third array.
Input 
5
1 2 3 4 5
2 8 3 4 8
Output
3 10 6 8 13
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int arr1[n];
    int arr2[n];
    int arr3[n];

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr1[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr2[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        arr3[i] = arr1[i] + arr2[i];
    }

    for (int i = 0; i < n; i++) {
        printf("%d", arr3[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}