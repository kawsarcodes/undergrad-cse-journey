/*
Problem: Program that will calculate the circumference of a circle having radius r.
Input 
5
Output
Area:  31.4
*/

#include <stdio.h>

int main() {
    double r;
    const double PI = 3.1416;
    
    if (scanf("%lf", &r) != 1) {
        return 1;
    }
    
    double circumference = 2 * PI * r;
    printf("Area:  %.2f\n", circumference);
    
    return 0;
}