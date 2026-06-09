
/*
Problem: Evaluate round up, round down, and absolute value metrics.
Input 
10.6
Output
A = 11, B = 10, C = 10.6
*/

#include <stdio.h>
#include <math.h>

int main() {
    double x;
    
    if (scanf("%lf", &x) != 1) {
        return 1;
    }
    
    double a = ceil(x);
    double b = floor(x);
    double c = fabs(x);
    
    printf("A = %.0f, B = %.0f, C = %.1f\n", a, b, c);
    
    return 0;
}