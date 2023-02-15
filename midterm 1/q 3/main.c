/*
 ============================================================================
 Name        : midterm1
 Author      : Ahmed badry mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Mid term1 , Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
void prime(int x, int y) {
    int i, j, c;
    for (i = x; i <= y; i++) {
        c = 0;
        for (j = 2; j <= i; j++) {
            if ((i % j) == 0) {
                c++;
            }}
        if (c == 1) {
            printf("%d\t", i);
        }}}
int main() {
    int num1, num2;
    printf("num1=");
    if (scanf("%d", &num1) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    printf("num2=");
    if (scanf("%d", &num2) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    prime(num1, num2);
    return 0;
}
