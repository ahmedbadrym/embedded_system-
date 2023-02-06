#include <stdio.h>
#include <stdlib.h>

int main()
{ int i,y,c=0;
printf("enter a string\n");
char g[100],x;
gets(g);
printf("enter a character to find frequency\n");
scanf("%c",&x);
y=strlen(g);
for(i=0;i<y;i++){
if(g[i]==x){
c++;}}

printf("\nthe frequency of %c is: %d",x,c);

    return 0;
}
