#include <stdio.h>
#include <stdlib.h>

 char x;
void rev(char a[100])

{
 char y;
   y=strlen(a)-x;

   if(y>=0){
   printf("%c",a[--y]);
   x++;
   rev(a);}


}
int main()
{
    printf("enter a sentence\n");
   char a[100];
   gets(a);
   rev(a);

    return 0;
}
