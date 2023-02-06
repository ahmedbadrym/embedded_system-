#include <stdio.h>
#include <stdlib.h>

int main()
{ int l,i,y;
    printf("enter the string:\n");
char g[100],r[100];
gets(g);
 l=strlen(g);
 y=l;
 for(i=0;i<l;i++){
 r[i]=g[--y] ;}
  printf(" the reverse:");
 for(i=0;i<l;i++)
   printf("%c",r[i]);
    return 0;
}
