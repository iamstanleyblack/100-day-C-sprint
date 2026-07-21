/*
we can add as many dimensions as we want to our arrays which will be stored in memory in row-major order. so in a 2D array, the first index listed indicates the row, and the second indicates the column

#include<stdio.h>
int main() {
    int row, col;
    int a[2][5] = {
        // We initialize a 2D array here
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9}
    };
for (row = 0; row < 2; row++){
    for(col = 0; col < 5; col++){
        printf("(%d, %d) = %d\n", row, col, a[row][col]);    }
}
}

// ARRAYS AND POINTERS
#include<stdio.h>
int main() {
    int a[5] = {11, 22, 33, 44, 55};
    int *p;

    p = &a[0]; // p points to the array's first element

    printf("%d\n", *p); // this will print 11 since its the irst element(element 0)
    // So, p = &a[0]; is the same as p = a;
    // referring to the array name is the same as getting a pointer to the first element of the array!
}

// PASSING SINGLE DIMENSTIONAL ARRAYS TO FUNCTIONS

if you pass an array to a function, you re passing a pointer to the first element in the array
However, if the function has a pointer to the dats, it is able to manipulate that data! So changes that a function mkes to an array will be visible back out in the caller

#include<stdio.h>
void double_array(int *a, int len)
{
    for(int i = 0; i < len; i++)
    a[i] *= 2;
}
int main(void)
{
    int x[5] = {1, 2, 3, 4, 5};
    double_array(x, 5);
    for(int i = 0; i < 5; i++)
    printf("%d\n", x[i]); // 
return 0;
}
// Passing Multidimensional Arrays to Functions


#include<stdio.h>
void print_2D_array(int a[2][3])
{
    for (int row = 0; row < 2; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            printf("%d ", a[row][col]);
        printf("\n");
        }
    }
}

int main(void)
{
    int x[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    print_2D_array(x);
}

// STRINGS
strings in C are  sequences of characters in double quotes
we assign a string to a variable in C using char *s
e.g. char *s = "Hello, World!";

string variable 's' here is actually a pointer to the first character in that string, that is 'H'. To print the string we use the string format specifier that is %s
#include<stdio.h>
int main() {
    char *s = "Hello World!\n";
    printf("We are printing %s\n", s);
    return 0;
}

#include<stdio.h>
int main() {
    char s[] = "Hello World!";
    for(int i = 0; i < 13; i++){
        printf("%c", s[i]);
        printf("\n");
    }
}
    // String initializers
    char *s = "Hello, World\n";
    char t[] = "Hello Again\n";
#include<stdio.h>
int main() {
    char *s = "Hello World";

    s[0] = 'z'; // we wil get an error here since we are trying to mutate a string literal
    print(' %s\n', s);
}

NB:/- If we have apoointer to a string literal, we shouldnt try to change it. If we use a string in double quotes to initialize an array then that is not actually a string literal


    #include<stdio.h>
    int main() {
        char t[] = "Hello Again!"; // t here is an array copy of the string
        t[0] = 'z'; 
        printf("%s\n", t); // this will work
    }

    to get the string length, we need to add a different header file called <string.h> and here we will be using a function called strlen()

#include<stdio.h>
#include<string.h>
int main()
{
    char *s = "Hello World";
    printf("The string is %zu bytes long.\n", strlen(s));// the strlen() function will return type size_t which is an integer type so we cn use it for integer math. we print size_t with a %zu formatter
}

In C, a 'string' is defined by two basic characteristics:
1. As a pointer to the first character in the string
2. As a zero-valued byte somewhere in memory after the pointer that indicates the end of the string

A NULL character can be written in C code as \0 though we dont oftenhave to do this
// Copying a string
in C, if we want to make a copy of a string, we have to copy it a byte at a time meaning that we're going to take the individual bytes of the string from one plece in memory and duplicate them somewhere else in memory. and this is made easier using the strcpy() function



#include<stdio.h>
#include<string.h>
int main() 
{
    char s[] = "Hello World";
    char t[100]; // Each char is one byte
    strcpy(t, s); // This makes a copy of the sting
    // Now 't' has "Hello World" even though it had nothing inside it before
    t[0] = 'z'; // We now modify the "Hello World" that is now in t, not he one in s.

    printf(" S remains unchanged and prints %s\n", s); // this prints "Hello World" since it has not been modified
    printf("T has been changed and prints %s\n", t); // This prints "zello World" since we only modified t
    return 0;

    
}

With strcpy() function, the destination pointer is the first argument and the source pointer is the second argument
*/
