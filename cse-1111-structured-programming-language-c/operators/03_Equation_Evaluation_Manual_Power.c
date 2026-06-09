
/*
Problem: Program that will take two numbers (a, b) as inputs and compute the value of the equation without using math.h
Input 
5            10.5
Output
X = 2.315475
*/

#include <stdio.h>

int main() {
    double a, b;
    
    if (scanf("%lf %lf", &a, &b) != 2) {
        return 1;
    }
    
    double a2 = a * a;
    double a3 = a * a * a;
    double b2 = b * b;
    double b3 = b * b * b;
    
    double numerator = (3.31 * a2) + (2.01 * b3);
    double denominator = (7.16 * b2) + (2.01 * a3);
    
    if (denominator != 0.0) {
        double x = numerator / denominator;
        printf("X = %f\n", x);
    }
    
    return 0;
}