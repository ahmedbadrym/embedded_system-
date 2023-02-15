
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
int sum;
int s(int num){
if(num<=100){
sum+=num;
s(++num);
}
    return sum;
}
int main()
{int x=1;
    printf("%d",s(x));
    return 0;
}
