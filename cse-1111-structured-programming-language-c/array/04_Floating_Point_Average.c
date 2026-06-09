/*
Problem: WAP that will take n floating point numbers into an array, and then find the average of those numbers.
Input 
5
1.2  5.6  10.3  4.5  5.2
Output
5.36
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    double arr[n];
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        sum += arr[i];
    }

    if (n > 0) {
        printf("%g\n", sum / n);
    }

    return 0;
}