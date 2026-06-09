/*
Problem: Player-1 picks a number X and Player-2 has to guess that number within N tries. For each wrong guess, print “Wrong, N-1 Choice(s) Left!”. If matched, print “Right, Player-2 wins!” and terminate. Otherwise after completion of N wrong tries, print “Player-1 wins!”.
Input 
5 3
12    8    5
Output
Wrong, 2 Choice(s) Left!
Wrong, 1 Choice(s) Left!
Right, Player-2 wins!
*/

#include <stdio.h>

int main() {
    int secret, maxTries, guess;
    int won = 0;

    if (scanf("%d %d", &secret, &maxTries) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    for (int i = 0; i < maxTries; i++) {
        if (scanf("%d", &guess) != 1) {
            return 1;
        }

        if (guess == secret) {
            printf("Right, Player-2 wins!\n");
            won = 1;
            break;
        } else {
            printf("Wrong, %d Choice(s) Left!\n", maxTries - 1 - i);
        }
    }

    if (!won) {
        printf("Player-1 wins!\n");
    }

    return 0;
}