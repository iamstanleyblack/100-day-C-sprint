/*
A pointer is a reference to a nother variable and it references the other variable by pointing to it.
When you have a pointer to a variable or a reference to a variable, you can use the original variable through the pointer by dereferencing the pointer.
if we have a variable 'var1' and we have a pointer to this variable called 'pointer1', we can use the dereferenced pointer 'pointer1' exactly as if it were the original 'var1'

#include<stdio.h>
int main() {
    int i;
    int *p; // this is Not a dereference, this is a pointer of type int
    p = &i; // p now points to i, p holds the address of i
    i = 10; // i variable has a value of 10
    *p = 20; // p now points to 20
    printf("i is %d\n and we have used var i", i); // this will print 20
    printf("i is still %d yet we have used *p(dereferenced pointer)\n", *p); // this prints 20 too because we are dereferencing the pointer 
}



#include<stdio.h>
void increment(int *p) // it accepts a pointer to an int
{
    *p = *p + 1; // add one to the thing p points to

}

int main(void){
    int i = 10;
    int *j = &i; //the address-of operator(&) turns j into a pointer to i which is an integer
    printf("i is %d\n", i); // this will print 10
    printf("i is also %d\n", *j); // this will print 10

    increment(j); // j is an int* to i(int pointer(pointer of type int))
    printf("i is %d\n", i); // this will print 11fd
}

if you want the function to modify the thing that you're passing in such that yo see the result, you will have to pass a pointer to that thing

// the NULL Pointer
any ponter variable of any type can be set to NULL which indicates that this pointer doesn't point to anything

if we thererfore try to dereference it, this wll probably lead toa  crash //NB:/- AVOID TRYING TO DEREFERENCE A NULL POINTER AS SOMETHING BAD MIGHT HAPPEN.


//DECLARING A POINTER
int a;
int b;
// we can just do this too:
int a, b;
/// But can we make the one below into a single line?
int a;
int *p;

// same thing
int a, *p; // coz the asterisk just goes before the variable name that it is a pointer

int *p, q; // p is a pointer to an int; q is just an int.
// but what of the one below?

int* p, q; // well, p is a pointer to an int and q is just an int.

// but what of here?
int *a, b, c, *d, e, *f, g, h, *i;
// the ones with an asterisk just before ie a, d, f, i are pointers

sizeof and pointers. 
int *p;
printf("%zu\n", sizeof(int)); // this will print the size of int

printf("%zu\n", sizeof p); // this prints the size of int too since p is of type int

printf("%zu\n", sizeof *p); // this will also print the size of int(*p is of type int)


    #include<stdio.h>
    int main(){
        int *p;
printf("%zu\n", sizeof(int)); // this will print the size of int

printf("%zu\n", sizeof p); // this prints the size of int too since p is of type int

printf("%zu\n", sizeof *p); // this will also print the size of int(*p is of type int)
        return 0;
    }


     // sizeof is all about the type of the expression and not the variables in the epression themselves.



//ARRAY


#include<stdio.h>
int main() {
    int i;
    float f[4]; // declaring an array of 4 floats
    f[0] = 3.14159; // indexing starts at 0
    f[1] = 1.41421;
    f[2] = 1.61803;
    f[3] = 2.71828;
    // printing them
    for(i = 0; i < 4; i++){
        printf("%f\n", f[i]);
    }
}

when you declare an array you have to give it a size

in the above example, we made an array of 4 floats. we know this by the value in the square brackets in the declaration

we can later on in subsequent  lines, access the values in the array, setting them or getting them again with square brackets

if an int is 4 bytes and the arry is 32 bytes then there must be rroom for 8 ints in the array.(ie 32 / 4 giving us 8 arrays)

ARRAY INITIALIZERS


*/
#include<stdio.h>
int main(void)
{}