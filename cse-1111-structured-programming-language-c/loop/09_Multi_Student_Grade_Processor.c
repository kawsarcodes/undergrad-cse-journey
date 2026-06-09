/*
Problem: Write a program (WAP) that will find the grade of N students based on weighted scores: Attendance 5%, Assignments 10%, Class Tests 15%, Midterm 30%, Final 40%.
Input 
2
5     10      15      44.5     92.5
0     7.5       5       20        55.5
Output
Student 1 : A
Student 2 : F
*/

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        double attendance, assignment, classTest, midterm, finalExam;

        if (scanf("%lf %lf %lf %lf %lf", &attendance, &assignment, &classTest, &midterm, &finalExam) != 5) {
            return 1;
        }

        double totalMark = (attendance * 1.0) + (assignment * 1.0) + (classTest * 1.0) + (midterm * 0.6) + (finalExam * 0.4);

        printf("Student %d : ", i);
        if (totalMark >= 90.0) printf("A\n");
        else if (totalMark >= 86.0) printf("A-\n");
        else if (totalMark >= 82.0) printf("B+\n");
        else if (totalMark >= 78.0) printf("B\n");
        else if (totalMark >= 74.0) printf("B-\n");
        else if (totalMark >= 70.0) printf("C+\n");
        else if (totalMark >= 66.0) printf("C\n");
        else if (totalMark >= 62.0) printf("C-\n");
        else if (totalMark >= 58.0) printf("D+\n");
        else if (totalMark >= 55.0) printf("D\n");
        else printf("F\n");
    }

    return 0;
}