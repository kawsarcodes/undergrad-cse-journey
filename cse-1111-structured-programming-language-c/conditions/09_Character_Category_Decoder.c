/*
Problem: Program that will categorize a single character that is entered at the terminal, whether it is an alphabet, a digit or a special character (Without math.h).
Input 
*
Output
Special
*/

#include <stdio.h>

int main() {
    char ch;

    if (scanf(" %c", &ch) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        printf("Alphabet\n");
    } else if (ch >= '0' && ch <= '9') {
        printf("Digit\n");
    } else {
        printf("Special\n");
    }

    return 0;
}