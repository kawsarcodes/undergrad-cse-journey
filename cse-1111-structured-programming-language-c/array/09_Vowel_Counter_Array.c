/*
Problem: WAP that will take n alphabets into an array, and then count number of vowels in that array.
Input 
7
AKIOUEH
Output
Count: 5
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    char arr[n + 1];
    if (scanf("%s", arr) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int count = 0;
    for (int i = 0; i < n && arr[i] != '\0'; i++) {
        char ch = arr[i];
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
            ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }

    printf("Count: %d\n", count);

    return 0;
}