#include <stdio.h>
#include <stdlib.h>

int main()
{ int x,i;
printf("enter the numbers of data");
scanf("%d",&x);
float arr [100],avg,sum=0 ;
for (i=0;i<x;i++){
 printf(" %d .enter number",i+1);
scanf("%f",&arr[i]);
sum=sum+arr[i];}
avg=sum/x;
printf("the avg is %.2f",avg);
return 0;
}
