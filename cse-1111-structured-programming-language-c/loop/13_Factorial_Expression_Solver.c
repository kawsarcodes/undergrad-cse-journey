/*
Problem: Write a program (WAP) that will print the factorial ( N!) of a given number N.
Input 
4
Output
4! = 4 X 3 X 2 X 1 = 24
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("%d! = ", n);
    long long factorial = 1;

    for (int i = n; i >= 1; i--) {
        printf("%d", i);
        factorial *= i;
        if (i > 1) {
            printf(" X ");
        }
    }

    printf(" = %lld\n", factorial);

    return 0;
}