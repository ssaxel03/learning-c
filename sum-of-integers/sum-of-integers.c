#include <stdio.h>

int main() {
    int x, y, sum;

    printf("x: ");
    scanf("%d", &x);

    printf("y: ");
    scanf("%d", &y);

    sum = x + y;

    printf("%d + %d = %d\n", x, y, sum);

    return 0;
}