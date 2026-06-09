
/*
Problem: Program that will increment and decrement a number X by 1 inside the printf function.
Input 
5
Output
X++ :    5,++X :    6,X- -  :    5,--X   :    4
*/

#include <stdio.h>

int main() {
    int x;
    
    if (scanf("%d", &x) != 1) {
        return 1;
    }
    
    int temp = x;
    printf("X++ :    %d,", temp++);
    
    temp = x;
    printf("++X :    %d,", ++temp);
    
    temp = x;
    printf("X- -  :    %d,", temp--);
    
    temp = x;
    printf("--X   :    %d\n", --temp);
    
    return 0;
}