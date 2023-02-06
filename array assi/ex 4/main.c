#include <stdio.h>
#include <stdlib.h>

int main()
{

int x,l,v,i,j;
printf("enter the size of array \n ");
scanf("%d",&x);
int arr[x];
for(i=0;i<x;i++){
    arr[i]=i+1;
     printf("%d\t",arr[i]);}
    printf("enter the element to be inserted: \n");
  scanf("%d",&v);
   printf("enter the location \n");
   scanf("%d",&l);
   for(j=l;j<=x;j++){
       if (j==x)
       arr[x]=x;
   else
    arr[j]=arr[j]-1;}
      arr[l-1] =v;
    for(i=0;i<=x;i++)
       printf("%d\t",arr[i]);

    return 0;
}
