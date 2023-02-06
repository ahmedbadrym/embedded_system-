#include <stdio.h>
#include <stdlib.h>

void clear_bit(int *num, int bit) {
    *num &= ~(1 << bit);
}

int main()
{
    int num ,bit;
    printf("entetr the number:\n");
    scanf("%d",&num);
     printf("entetr the bit position:\n");
    scanf("%d",&bit);
    clear_bit(&num, bit);
    printf("The number is: %d\n", num);
    return 0;
}
