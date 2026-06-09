/*
Problem: Program that will take the final score of a student in a particular subject as input and find his/her grade.
Input 
91.5
Output
Grade: A
*/

#include <stdio.h>

int main() {
    float score;

    if (scanf("%f", &score) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Grade: ");
    if (score >= 90 && score <= 100) printf("A\n");
    else if (score >= 86 && score < 90) printf("A-\n");
    else if (score >= 82 && score < 86) printf("B+\n");
    else if (score >= 78 && score < 82) printf("B\n");
    else if (score >= 74 && score < 78) printf("B-\n");
    else if (score >= 70 && score < 74) printf("C+\n");
    else if (score >= 66 && score < 70) printf("C\n");
    else if (score >= 62 && score < 66) printf("C-\n");
    else if (score >= 58 && score < 62) printf("D+\n");
    else if (score >= 55 && score < 58) printf("D\n");
    else printf("F\n");

    return 0;
}