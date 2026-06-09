
/*
Problem: Program to find size of int, float, double and char of the system.
Input 
[No Input Parameters Required]
Output
Size of int in byte(s) = 4,Size of float in byte(s) = 4,Size of double in byte(s) = 8,Size of char in byte(s) = 1
*/

#include <stdio.h>

int main() {
    printf("Size of int in byte(s) = %zu,", sizeof(int));
    printf("Size of float in byte(s) = %zu,", sizeof(float));
    printf("Size of double in byte(s) = %zu,", sizeof(double));
    printf("Size of char in byte(s) = %zu\n", sizeof(char));
    
    return 0;
}