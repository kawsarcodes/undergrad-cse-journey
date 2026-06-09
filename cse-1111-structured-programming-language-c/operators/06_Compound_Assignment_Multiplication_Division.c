
/*
Problem: Program that will multiply and divide a number X by Y. (Use *= and /= operators)
Input 
56       10
Output
Multiplication:    560
Division:   5
*/

#include <stdio.h>

int main() {
    int x, y;
    
    if (scanf("%d %d", &x, &y) != 2) {
        return 1;
    }
    
    int originalX = x;
    
    x *= y;
    printf("Multiplication:    %d\n", x);
    
    if (y != 0) {
        originalX /= y;
        printf("Division:   %d\n", originalX);
    }
    
    return 0;
}