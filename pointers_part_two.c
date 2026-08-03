/*
Adding pointers
*/
#include<stdio.h>
int main(){
int a[5] = {11, 22, 33, 44, 55};

// getting a pointer to the first element in the array
int *p = &a[0];
printf("%d\n", *p);
}