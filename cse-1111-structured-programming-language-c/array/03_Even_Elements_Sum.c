/*
Problem: WAP that will take n integer numbers into an array, and then sum up all the even integers in that array.
Input 
5
1  2  3  4  5
Output
6
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }

    printf("%d\n", sum);

    return 0;
}