/*
Problem: WAP that will calculate following mathematical function for the input of x using the series approximation: Sinx = x - x^3/3! + x^5/5! - x^7/7! + ...
Input 
1
Output
0.841
*/

#include <stdio.h>

int main() {
    double x;

    if (scanf("%lf", &x) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    double term = x;
    double sum = x;
    int count = 1;

    for (int i = 3; count <= 15; i += 2) {
        term = -term * x * x / (i * (i - 1));
        sum += term;
        count++;
    }

    printf("%.3f\n", sum);

    return 0;
}