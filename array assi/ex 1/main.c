#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x[2][2];
    float y[2][2];
    float z[2][2] ;
   int i;
   int n;

    for(i=0;i<2;i++){
    for(n=0;n<2;n++){
    printf("enter the number of element x%d%d ",i,n );
    scanf("%f",&x[i][n]);}}
    int o;
    int p;
     for(o=0;o<2;o++){
    for(p=0;p<2;p++){
    printf("enter the number of elements y%d%d ",o,p );
    scanf("%f",&y[o][p]);}}
    int c,v;
     printf("sum of matrix \n");
     for(c=0;c<2;c++){
    for(v=0;v<2;v++){
   z[c][v]=x[c][v]+y[c][v];

   printf("%.1f\t",z[c][v]);
   if (v==1)
    printf("\n");
   }}

    return 0;
}
