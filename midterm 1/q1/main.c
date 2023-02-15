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
  int rem,s,y;
int sum (int num){
if(num!=0){
rem=num%10;
s+=rem;
y=s;
sum(num/10);
s=0;}
else
    return 0;
return y;

}
int main(){
int x,y=3,res;
 // this while for two test cases
while(--y){
printf("INPUT NUMBER:");
scanf("%d",&x);
res=sum(x);
printf(" The Output:%d\n",res);
}
return 0;
}

