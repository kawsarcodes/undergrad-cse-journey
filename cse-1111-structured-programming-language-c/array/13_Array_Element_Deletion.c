/*
Problem: WAP that will take n integer numbers as input in an array and then delete a number from a position specified by the user in the array.
Input 
5
32 14 9 48 6
0
Output
14 9 48 6
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

    int position;
    if (scanf("%d", &position) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (position < 0 || position >= n) {
        printf("Invalid position.\n");
        return 1;
    }

    for (int i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    for (int i = 0; i < n - 1; i++) {
        printf("%d", arr[i]);
        if (i < n - 2) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}