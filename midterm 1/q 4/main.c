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
int rev (int n){
    int num ;
if(n!=0){
    num=n%10;
printf("%d",num);
    rev(n/10);
    }
    else
        return 0;
}
int main()
{
     int x,y=3;
      // this while for two test cases
     while(--y){
    printf("INPUT:");
    scanf("%d",&x);
     printf("Output:");
    rev(x);
     printf("\n");
    }

    return 0;
}
