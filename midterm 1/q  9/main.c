
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
void rev(char a [],int y){
    int i,j,k;
    for(i=0;i<=y-1;i++){
   if(a[i]==' '){
        k=i;
    for(j=i+1;j<=y-1;j++)
   printf("%c",a[j]);}
                       }
     printf(" ");
    for(i=0;i<k;i++)
      printf("%c",a[i]);


}
int main()
{int y;
    char a[100];
    printf("INPUT:");
    gets(a);
    y=strlen(a);
    printf("INPUT:");
  rev(a,y);
    return 0;
}
