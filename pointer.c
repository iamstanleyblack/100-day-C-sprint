// a pointer is a variable that holds an address
/*
for example 
int someVariable = 3;
int *ptr = &someVariable;
This variable is the name for the memory space we have stored the value 3
The memory spot that 3 lives has an address like 0x7ffee4c9aca whcih is just a number identifying where in memory it lives.
So, ptr is a pointer holding someVariable's address
&someVarialbe - the ampersand(&) operator fetches the address of someVariable
ptr - This is a new vairable declared with * whose value it that address
*ptr - This is dereferencing ptr which gets you back the value at that address(3)
*/

#include<stdio.h>
int main(){
    int someVariable = 23;
    int *someVariablesPointer = &someVariable;

    printf("Some Variable's value is %d\n", someVariable);

    printf("The address where some variable lives in is %d\n", someVariablesPointer);

    printf("In order to dereference the pointer value we use the * symbol in the printf\n");

    printf("Like this *someVariable and so we have %d\n", *someVariablesPointer);


    return 0;
}


