/*
Problem: Write a program that takes an integer number n as input and find out the sum of the following series up to n terms: 1 + 12 + 123 + 1234 + …….
Input 
3
Output
136
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    long long currentTerm = 0;
    long long totalSum = 0;

    for (int i = 1; i <= n; i++) {
        currentTerm = (currentTerm * 10) + i;
        totalSum += currentTerm;
    }

    printf("%lld\n", totalSum);

    return 0;
}