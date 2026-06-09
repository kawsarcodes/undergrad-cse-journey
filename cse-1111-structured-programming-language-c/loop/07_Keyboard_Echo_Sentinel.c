/*
Problem: Write a program (WAP) that will run and show keyboard inputs until the user types an ’A’ at the keyboard.
Input 
X 1 a A
Output
Input 1: X
Input 2: 1
Input 3: a
*/

#include <stdio.h>

int main() {
    char ch;
    int counter = 1;

    while (1) {
        if (scanf(" %c", &ch) != 1) {
            break;
        }

        if (ch == 'A') {
            break;
        }

        printf("Input %d: %c\n", counter, ch);
        counter++;
    }

    return 0;
}