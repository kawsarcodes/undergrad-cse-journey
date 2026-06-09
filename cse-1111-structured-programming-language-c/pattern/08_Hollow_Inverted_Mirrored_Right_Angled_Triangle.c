/*---

Pattern 8: Hollow Inverted Mirrored Right Angled Triangle

* * * * * 
  *     * 
    *   * 
      * * 
        * 

---*/

#include <stdio.h>
int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++)
            printf("  ");
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == n)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}