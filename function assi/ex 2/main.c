#include <stdio.h>
#include <stdlib.h>

int factorial(int x) {
    int y;
    if (x== 0)
        return 1;
  y= x* factorial(x - 1);
    return y;
}

int main() {
    int x, fact;
    printf("Enter an integer: ");
    scanf("%d", &x);
    fact = factorial(x);
    printf("Factorial of %d = %d\n", x, fact);
    return 0;
}
