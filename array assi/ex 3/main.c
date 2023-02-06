#include <stdio.h>
#include <stdlib.h>

int main()
{int r,c,x,y;
printf("enter the size of the matrix");
scanf("%d %d",&x,&y);
int m [x][y],t[y][x];
for(r=0;r<x;r++){
for(c=0;c<y;c++){
printf("enter the element m%d %d:\t",r,c);
 scanf("%d",&m[r][c]);
t[c][r]=m[r][c];
 }}
 printf("entered matrix is: \n");
 for(r=0;r<x;r++){
printf("\n");
for(c=0;c<y;c++)
 printf("%d \t",m[r][c]);}
 printf("\nthe transpose of the matrix is: \n");
 for(r=0;r<y;r++){
printf("\n");
for(c=0;c<x;c++)
 printf("%d \t",t[r][c]);}




    return 0;
}
