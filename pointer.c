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

Just like an int variable can hold the value 12, a pointer variable can hold the address of data
All the stuff below therefore mean the same thing:
Index into memory == address == location


And so a pointer variable holds that address number just like a float variable might hold 3.14159


#include<stdio.h>
int main(){
    int someVariable = 23;
    int *someVariablesPointer = &someVariable;

    printf("Some Variable's value is %d\n", someVariable);

    printf("The address where some variable lives in is %p\n", someVariablesPointer); // notice i used a %p here which prints a pointer

    printf("In order to dereference the pointer value we use the * symbol in the printf\n");

    printf("Like this *someVariable and so we have %d\n", *someVariablesPointer);


    return 0;
}


#include<stdio.h>
int main() {
    int i = 10;
    printf("The value of i is %d\n", i);
    printf("And its address is %p\n", (void *)&i);// dont worry about (the void *). i will be learnign that later
    return 0;
}

the number printed as the address is tha location of i/ the pointer to i. it is a pointer because it lets me know where i is in memory. Like a home address written o a scrap paper tells ;you where you can find a particular house, this number indicates to us where in memory we can find the value of i

*/
