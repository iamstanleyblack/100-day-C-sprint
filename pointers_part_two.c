/*
Adding pointers

#include<stdio.h>
int main(){
int a[5] = {11, 22, 33, 44, 55};

// getting a pointer to the first element in the array
int *p = &a[0];
printf("%d\n", *p); // this will print 11
// adding 1 to the pointer will print the next element in the array
printf("%d\n", *(p + 1));
// C knows that p is a pointer to an int and so it knows the sizeof an int and it knows to skip that many bytes t get to the next int after the first one
// Both printf("%d\n", *p); and printf("%d\n", *(p + 0)); will print 11
printf("%d\n", *(p + 0));
printf("We are now iterating over the elements of the array.\n");
for (int i = 0; i < 5; i++) {
    printf("%d\n", *(p + i));
}
}

How does this work?
the memory is like a big array where byte is stored at each array index. And the array index into memory has a few names like index into memory, location, address, pointer
---So a pointer is an index into some memory

*/
