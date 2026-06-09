/*
Problem: Program for "Guessing Game" where Player-1 picks a number X and Player-2 has to guess within N=3 tries without using loops, break, or continue.
Input 
20     12    8    5
Output
Wrong, 2 Chance(s) Left!
Wrong, 1 Chance(s) Left!
Wrong, 0 Chance(s) Left!
Player-1 wins!
*/

#include <stdio.h>

int main() {
    int secret, guess;
    int done = 0;

    if (scanf("%d", &secret) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (!done) {
        if (scanf("%d", &guess) != 1) return 1;
        if (guess == secret) {
            printf("Right, Player-2 wins!\n");
            done = 1;
        } else {
            printf("Wrong, 2 Chance(s) Left!\n");
        }
    }

    if (!done) {
        if (scanf("%d", &guess) != 1) return 1;
        if (guess == secret) {
            printf("Right, Player-2 wins!\n");
            done = 1;
        } else {
            printf("Wrong, 1 Chance(s) Left!\n");
        }
    }

    if (!done) {
        if (scanf("%d", &guess) != 1) return 1;
        if (guess == secret) {
            printf("Right, Player-2 wins!\n");
            done = 1;
        } else {
            printf("Wrong, 0 Chance(s) Left!\n");
            printf("Player-1 wins!\n");
        }
    }

    return 0;
}