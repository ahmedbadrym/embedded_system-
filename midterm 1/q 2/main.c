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
#include <math.h>

void sqr(int x) {
    double sqrt_x = sqrt(x);


    printf("Output: %.3f\n", sqrt_x);

}

int main() {
    int num1,y=3;
      // this while for two test cases
while(--y){
    printf("INPUT:");
    scanf("%d", &num1);
sqr(num1);
}
return 0;
}
