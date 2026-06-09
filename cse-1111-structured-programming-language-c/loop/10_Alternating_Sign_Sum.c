/*
Problem: Write a program (WAP) that will give the sum of first Nth terms for the following series.
1 ,  -2 ,  3 ,  -4 ,  5 ,  -6 ,  7 ,  -8 , 9, -10, 11, -12, 13, -14,  …….
Input 
3
Output
Result: 2
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            sum += i;
        } else {
            sum -= i;
        }
    }

    printf("Result: %d\n", sum);

    return 0;
}