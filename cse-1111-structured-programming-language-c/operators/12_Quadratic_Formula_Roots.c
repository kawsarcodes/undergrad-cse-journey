
/*
Problem: Program that will calculate the roots of a quadratic equation.
Input 
2      4     -16
Output
2.00    -4.00
*/

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        return 1;
    }
    
    double discriminant = (b * b) - (4.0 * a * c);
    
    if (discriminant < 0) {
        printf("Imaginary\n");
    } else {
        double root1 = (-b + sqrt(discriminant)) / (2.0 * a);
        double root2 = (-b - sqrt(discriminant)) / (2.0 * a);
        printf("%.2f    %.2f\n", root1, root2);
    }
    
    return 0;
}