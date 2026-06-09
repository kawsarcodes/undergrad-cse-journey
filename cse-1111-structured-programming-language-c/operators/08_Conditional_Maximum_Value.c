
/*
Problem: Program that will take two numbers as inputs and print the maximum value. (Using conditional operator - ?)
Input 
20     100
Output
Max: 100
*/

#include <stdio.h>

int main() {
    int x, y;
    
    if (scanf("%d %d", &x, &y) != 2) {
        return 1;
    }
    
    int max = (x > y) ? x : y;
    printf("Max: %d\n", max);
    
    return 0;
}