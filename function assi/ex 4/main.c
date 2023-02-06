#include <stdio.h>
#include <stdlib.h>
int power(int x, int y) {
    int r;
    if (y == 1) {
        return x;
    }

    r = x * power(x, --y);
    return r;
}

int main() {
    int x, y;
    printf("Enter the base: ");
    scanf("%d", &x);
    printf("Enter the power: ");
    scanf("%d", &y);

    int result = power(x, y);
    printf("Result: %d\n", result);

    return 0;
}



