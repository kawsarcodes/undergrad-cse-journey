/*
Problem: Program that will construct a menu where choice 4 prompts for an additional inner selection choice case 1 or 2 to evaluate quotient or remainder.
Input 
-5     10.5     4     2
Output
Reminder:  -48
*/

#include <stdio.h>

int main() {
    float a, b;
    int choice, subCase;

    if (scanf("%f %f", &a, &b) != 2) {
        printf("Invalid input.\n");
        return 1;
    }
    if (scanf("%d", &choice) != 1) {
        return 1;
    }

    int intA = (int)a;
    int intB = (int)b;

    if (choice == 1) {
        printf("Addition: %g\n", a + b);
    } else if (choice == 2) {
        printf("Subtraction: %g\n", a - b);
    } else if (choice == 3) {
        printf("Multiplication: %g\n", a * b);
    } else if (choice == 4) {
        if (scanf("%d", &subCase) != 1) return 1;

        if (subCase == 1) {
            if (intB != 0) printf("Quotient: %d\n", intA / intB);
        } else if (subCase == 2) {
            if (intB != 0) printf("Reminder:  %d\n", intA % intB);
        }
    }

    return 0;
}