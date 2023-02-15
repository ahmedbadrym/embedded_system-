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
int Countones(int num)
{
	int x = 0 , sum = 0;
	while(num!= 0)
	{
		if( num & 1)
		{
			sum++;}
		else
		{
if(sum > x)
			{
    x = sum ;
}
sum = 0 ;}
		 num >>= 1 ;
	}
	if(sum > x)
	{
		x = sum ;
      	}
	return x;
}

int main()
{
	int n,y=3;
	while(--y){
	printf("\nINPUT:");
	scanf("%d",&n);
	printf("Output:");
	printf("%d",Countones(n));}
return 0;
}
