/*
Problem: WAP that will take n integer numbers into an array, and then find the maximum -minimum among them with its index position.
Input 
5
1  2  3  4  5
Output
Max: 5, Index: 4
Min: 1, Index: 0
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

    int maxVal = arr[0], maxIdx = 0;
    int minVal = arr[0], minIdx = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIdx = i;
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIdx = i;
        }
    }

    printf("Max: %d, Index: %d\n", maxVal, maxIdx);
    printf("Min: %d, Index: %d\n", minVal, minIdx);

    return 0;
}