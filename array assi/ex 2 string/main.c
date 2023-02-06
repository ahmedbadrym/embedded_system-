#include <stdio.h>
#include <stdlib.h>

int main()
{int x,i=0;
 printf("enter a string\n");
char g[100];
gets(g);

while(g[i]!=0){
    i++;
    x++;}
 printf("the length of string is %d",x);

    return 0;
}
