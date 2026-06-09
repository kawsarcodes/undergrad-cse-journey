/*
Problem: WAP that will take n integers into an array, and then search a number into that array. If found then print its index. If not found then print “NOT FOUND”.
Input 
8
7 8 1 3 2 6 4 3
3
Output
FOUND at index position: 3, 7 
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

    int target;
    if (scanf("%d", &target) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int indices[n];
    int foundCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            indices[foundCount++] = i;
        }
    }

    if (foundCount > 0) {
        printf("FOUND at index position: ");
        for (int i = 0; i < foundCount; i++) {
            printf("%d", indices[i]);
            if (i < foundCount - 1) {
                printf(", ");
            }
        }
        printf(" \n");
    } else {
        printf("NOT FOUND\n");
    }

    return 0;
}