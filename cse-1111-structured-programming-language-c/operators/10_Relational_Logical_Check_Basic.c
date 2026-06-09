
/*
Problem: Program that will evaluate truth values of simple relational statements.
Input 
10   -10   0
Output
1,0,1
*/

#include <stdio.h>

int main() {
    int a, b, c;
    
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        return 1;
    }
    
    int condition1 = (a + b <= 80);
    int condition2 = !(a + c);
    int condition3 = (a != 0);
    
    printf("%d,%d,%d\n", condition1, condition2, condition3);
    
    return 0;
}