/*
Problem: Write a program (WAP) that will calculate the result for the first Nth terms of the following series: 1^2.2 + 2^2.3 + 3^2.4 + 4^2.5 + …….
Input 
2
Output
Result: 14
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (long long)(i * i) * (i + 1);
    }

    printf("Result: %lld\n", sum);

    return 0;
}