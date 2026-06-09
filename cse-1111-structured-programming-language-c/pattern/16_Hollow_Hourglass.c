/*---

Pattern 16: Hollow Hourglass

* * * * * * * * *
  *           *
    *       *
      *   *
        *
      *   *
    *       *
  *           *
* * * * * * * * *

---*/

#include <stdio.h>
int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++)
            printf("  ");
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1 || i == n)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n - i; j++)
            printf("  ");
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1 || i == n)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}