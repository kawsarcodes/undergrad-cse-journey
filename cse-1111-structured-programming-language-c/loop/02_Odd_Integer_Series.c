/*
Problem: Write a program (WAP) that will print following series upto Nth terms.
1,  3 ,  5 , 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31  …….
Input 5
Output
1, 3, 5, 7, 9
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int current = 1;
    for (int i = 1; i <= n; i++) {
        printf("%d", current);
        if (i < n) {
            printf(", ");
        }
        current += 2;
    }
    printf("\n");

    return 0;
}