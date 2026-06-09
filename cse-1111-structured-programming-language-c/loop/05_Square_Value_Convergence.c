/*
Problem: Write a program (WAP) that will take two numbers X and Y as inputs. Then it will print the square of X and increment ( if X<Y ) or decrement ( if X>Y ) X by 1, until X reaches Y. If and when X is equal to Y, the program prints “Reached!”
Input 
10       5
Output
100, 81, 64, 49, 36, Reached!
*/

#include <stdio.h>

int main() {
    int x, y;

    if (scanf("%d %d", &x, &y) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    while (x != y) {
        printf("%d, ", x * x);
        if (x < y) {
            x++;
        } else {
            x--;
        }
    }
    printf("Reached!\n");

    return 0;
}