#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,z;
    printf("enter value of a: ");
    scanf("%f",&a);
     printf("enter value of b: ");
    scanf("%f",&b);
    z=a;
    a=b;
    b=z;
    printf(" after swaping :value of a: %f\n ",a);
     printf("after swaping : value of b: %f\n ",b);

    return 0;
}
