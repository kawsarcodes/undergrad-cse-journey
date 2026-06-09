/*
Problem: WAP that will take n integers into an array A. Now remove all duplicates numbers from that array. Finally print all elements from that array.
Input 
8
2 8 1 3 2 6 4 3
Output
2 8 1 3 6 4
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

    int uniqueCount = 0;
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            arr[uniqueCount++] = arr[i];
        }
    }

    for (int i = 0; i < uniqueCount; i++) {
        printf("%d", arr[i]);
        if (i < uniqueCount - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}