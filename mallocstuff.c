/*
This is one of the big areas of C that deals with manual memory management
Other languages uses reference counting, garbage collection or other means to determine when to allocate new memory for some date and when to deallocate it when no variables refer to it.
In C, some variables are automatically allocated and deallocated when they come into scope and leave scope. We call these automatic variables. They are your average run-of-the-mill block scope "local" variables
You can tell C explicitly to allocate for you a certain number of bytes that you can use as you please.
automatic local variables are allocated "on the stack", and manually allocated memory is called "on the heap"
all functions on this malloc is founc in the <stdlib.h> header file
The malloc() function accepts a number of bytes to allocate, and returns a void pointer to that block of newly-allocated memory. Since it is a void*, we can assign it into whatever pointer type we want, normally this will correspod in some way to the numbe rof byes you're allocating
If we want to allocate enough room for a single int, we can use sizeof(int) and pass that to malloc()
After we're done with some allocated memroy, we can call free() to indicate we're done with that memory and it can be used for something else. As an argument, we pass the same pointer we got from malloc() or a copy of it. It' is an undefined behavior to use a mememory region after we free() it

*/
/*
// we allocate space for a single int sizeof(int) bytes-worth:
int *p = malloc(sizeof(int));
*p = 12;
printf("%d\n", *p); // this prints 12
free(p); // we are done with that memrory
// *p = 31; // thsi brings error/undefined behavior since we cannot use *p after free()
*/
#include<stdio.h>
#include<stdlib.h> // this is required for malloc() and free()

int main(){
    int n = 5;
    int *pointer;
    pointer = (int *) malloc(n * sizeof(int)); // We allocate memory for 5 integers using malloc
    // in malloc(n * sizeof(int)),, malloc asks the operating system for a raw block of memrory on the heap. We then multiply n (5) by sizeof(int) to reserve the exact number of byte needed for five integers
    if (pointer == NULL){
        printf("The memory allocation failed!\n");
        return 1; // This will exit the program, 1 means we have encountered an error and so the program will exit
    }
    for (int i = 0; i < n; i++){
        pointer[i] = (i + 1) * 10;
    } // we store the data in the allocated memory here
    printf("The content stored are: "); // Here we print the data that is already stored in memory
    for (int i = 0; i < n; i++){
        printf("%d ", pointer[i]);
    }
    printf("\n");
    free(pointer); // We free the allocted memory here to prevent memory leaks and so after this, this variable "pointer" cannot be used

    pointer = NULL; // setting ponter to NULL is to avoid a dangling/empty pointer
    return 0;
}