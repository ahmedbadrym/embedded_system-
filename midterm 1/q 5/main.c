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
int count1(int n) {
    int count = 0;
    while(n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
int main()
{
    int x,res;
    int y=3;
    // this while for two test cases
    while(--y){
    printf("INPUT:");
    scanf("%d",&x);
    printf("Output:");
    res=count1(x);
       printf("%d\n",res);
              }

    return 0;

}
