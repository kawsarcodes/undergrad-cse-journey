/*
Problem: WAP that will take n integer numbers as input in an array and then insert a number in a position specified by the user in the array.
Input 
5
32 14 9 48 6
16 0
Output
16 32 14 9 48 6
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int arr[n + 1];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    int number, position;
    if (scanf("%d %d", &number, &position) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    if (position < 0 || position > n) {
        printf("Invalid position.\n");
        return 1;
    }

    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = number;

    for (int i = 0; i <= n; i++) {
        printf("%d", arr[i]);
        if (i < n) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}