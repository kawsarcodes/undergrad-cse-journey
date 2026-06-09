/*
Problem: Write a program (WAP) that will print Fibonacci series upto Nth terms.
1 ,  1 ,  2 ,  3 ,  5 ,  8 ,  13 ,  21 , 34, 55, 89,  …….
Input 
4
Output
1 ,  1 ,  2 ,  3
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    long long t1 = 1, t2 = 1;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("1");
        } else if (i == 2) {
            printf("1");
        } else {
            long long nextTerm = t1 + t2;
            printf("%lld", nextTerm);
            t1 = t2;
            t2 = nextTerm;
        }

        if (i < n) {
            printf(" ,  ");
        }
    }
    printf("\n");

    return 0;
}