
/*
Problem: Program that will evaluate complex conditional compound logical paths.
Input 
10   -10   0
Output
0,1,1
*/

#include <stdio.h>

int main() {
    int a, b, c;
    
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        return 1;
    }
    
    int res1 = (a + b <= 80 && b >= 0);
    int res2 = ((a - b) == 0 || c != 0);
    int res3 = (a != b || (b < a && c > 0));
    
    printf("%d,%d,%d\n", res1, res2, res3);
    
    return 0;
}