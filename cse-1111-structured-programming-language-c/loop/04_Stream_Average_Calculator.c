/*
Problem: Write a program (WAP) that will take N numbers as inputs and compute their average (Without using any array).
Input 
3
10         20        30.5
Output
AVG of 3 inputs:  20.166667
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    double sum = 0.0;
    double current;

    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &current) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        sum += current;
    }

    if (n > 0) {
        printf("AVG of %d inputs:  %f\n", n, sum / n);
    }

    return 0;
}