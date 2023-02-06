#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void prime(int x ,int y)
{
  int i,j,h;
  printf(" prim number between %d and %d are:\t",x,y);

  for(i=x;i<=y;i++)  {
        h=0;
  for(j=1;j<=i;j++){
    if (i%j==0)
    h++;}
  if(h==2)
  printf("%d\t",i);
}}
int main() {
    int l, n;
    printf("Enter two numbers: ");
    scanf("%d %d", &l, &n);
    prime(l, n);
    return 0;
}
