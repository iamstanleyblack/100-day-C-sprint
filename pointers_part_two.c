/*
Adding pointers
*/

#include<stdio.h>
int main(){
int a[5] = {11, 22, 33, 44, 55};

// getting a pointer to the first element in the array
int *p = &a[0];
printf("%d\n", *p); // this will print 11
// adding 1 to the pointer will print the next element in the array
printf("%d\n", *(p + 1));
}

