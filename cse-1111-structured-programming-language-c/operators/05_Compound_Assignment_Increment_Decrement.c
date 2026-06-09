
/*
Problem: Program that will increment and decrement a number X by Y. (Use += and -= operators)
Input 
5     10
Output
Incremented Value:    10
Decremented Value:   -5
*/

#include <stdio.h>

int main() {
    int x, y;
    
    if (scanf("%d %d", &x, &y) != 2) {
        return 1;
    }
    
    int originalX = x;
    
    x += y;
    printf("Incremented Value:    %d\n", x);
    
    originalX -= y;
    printf("Decremented Value:   %d\n", originalX);
    
    return 0;
}