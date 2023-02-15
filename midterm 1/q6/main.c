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
int findUnique(int a[], int size);

int main() {
    int x=3;
  // this while for two test cases
    while(--x){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
    printf("The unique number is: %d\n", findUnique(a, size));}

    return 0;
}

int findUnique(int a[], int size) {
    int unique = a[0];
    for (int i = 1; i < size; i++) {
        unique = unique ^ a[i];
    }
    return unique;
}
