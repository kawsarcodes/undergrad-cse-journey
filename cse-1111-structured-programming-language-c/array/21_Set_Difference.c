/*
Problem: WAP that will take n integers into an array A and m positive integers into array B. Now find the difference (set operation) of array A and B or (A-B).
Input 
3
1 2 3
2
4 5
Output
1 2 3
*/

#include <stdio.h>

int main() {
    int n, m;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    int a[n];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) return 1;
    }

    if (scanf("%d", &m) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    int b[m];
    for (int i = 0; i < m; i++) {
        if (scanf("%d", &b[i]) != 1) return 1;
    }

    int result[200];
    int resultCount = 0;

    for (int i = 0; i < n; i++) {
        int foundInB = 0;
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                foundInB = 1;
                break;
            }
        }
        if (!foundInB) {
            int alreadyAdded = 0;
            for (int k = 0; k < resultCount; k++) {
                if (result[k] == a[i]) {
                    alreadyAdded = 1;
                    break;
                }
            }
            if (!alreadyAdded) {
                result[resultCount++] = a[i];
            }
        }
    }

    for (int i = 0; i < resultCount; i++) {
        printf("%d", result[i]);
        if (i < resultCount - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}