
/*
Problem: Program that will evaluate precedence targeted equations.
Input 
9     12     3
Output
X = 10,Y = 4,Z = -1
*/

#include <stdio.h>

int main() {
    int a, b, c;
    
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        return 1;
    }
    
    int x = a - b / 3 + c * 2 - 1;
    int y = a - (b / (3 + c) * 2) - 1;
    int z = a - ((b / 3) + c * 2) - 1;
    
    printf("X = %d,Y = %d,Z = %d\n", x, y, z);
    
    return 0;
}