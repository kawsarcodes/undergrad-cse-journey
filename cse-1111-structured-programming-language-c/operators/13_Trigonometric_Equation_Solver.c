
/*
Problem: Program that will evaluate the equation 2 * cos^2(x) - 3 * sin(x) + sin(x^2)
Input 
30
Output
1.810066
*/

#include <stdio.h>
#include <math.h>

int main() {
    double degrees;
    const double PI = 3.1416;
    
    if (scanf("%lf", &degrees) != 1) {
        return 1;
    }
    
    double radX = degrees * (PI / 180.0);
    double radX2 = (degrees * degrees) * (PI / 180.0);
    
    double cosX = cos(radX);
    double result = (2.0 * cosX * cosX) - (3.0 * sin(radX)) + sin(radX2);
    
    printf("%f\n", result);
    
    return 0;
}