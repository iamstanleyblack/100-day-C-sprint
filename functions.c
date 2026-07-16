/*
A function is a self-contained, reusable block of code that performs a specific, well-defined task
Functions can accept a variety of arguments and return a value.
In C, the arguments and return value types are predeclared

#include<stdio.h>
int plus_one(int n) // The definition
{
return n + 1;
 // the int indicates the return type. Theh int n indicates that this fnunction take one int argument stored in a parameter n. A parameter is a special type of local variable into which the arguments are copied
}
 int main(void){ // the 'void' is a keyword that is used to indicate that the function accepts no arguments.
 You can also return void to indicate that you don't return a value
 int i = 10;
 j = plus_one(i); // this is the call to the function(function call)
 printf("i + 1 is %d\n", j);
 }


 ----------------------
 another example
 ----------------------
 #include <stdio.h>
 // The function below takes no arguments and returns no value
void hello(void)
{
printf("Hello, World!\n");
}
int main(void)
{
hello(); // This is the function call and it prints "Hello, World!"
}

// When you pass an argument to a functin, a copty of that argument gets made and stored in the corresponding parameter
If the arument is a variable, a copy of that variable gets made and stored in the parameter

--------------------
example
-------------------
#include<stdio.h>
void increment (int a)
{
a++;
}
int main (void)
{
int i = 10;
increment(i);
printf("i == %d\n", i); // This prints what?
}

// THis will infact print 10 instead of 11. Because the expressions passed to functions get copied onto their corresponding parameters and the parameter jis copied and not the original.
// i is 10 out in main() and we pass it to increment(). the corresponding parameter is called a in that function

#include<stdio.h>
int foo(void); // This is a  function prototype
int main(void)
{
int i;
// We can call foo() here before it's definition because the prototype has already been declared above
i = foo();
printf("%d\n", i) // 3490

}
int foo(void) // This is the definition, just like the prototype!
{
return 3490;
}
// If you don't declare your function before you use it (either with a prototype or its definition), you're performing something called an implicit declaration(introduced in C89) 
*/

//|-----------------------------------|
//|##################################|
//|##########FUNCTIONS IN C##########|
//|#################################|
//---------------------------------|

#include<stdio.h>
int product(int a, int b); // NB;/- FUNCTION PROTOTYPES ALSO END WITH A SEMI-COLON
float division(float a, float b);
int difference(int a, int b);
int addition(int a, int b);


int main(void)
{
    int a;
    int b;
    int prodf;
    int diff;
    float divf;
    int addf;
    int choice;
    printf("------------------------------------------\n");
    printf("Performing mathematical calculations\n");
    printf("------------------------------------------\n");
    printf("Enter the first number: \n");
    scanf("%d", &a);
    printf("Enter the second number: \n");
    scanf("%d", &b);
    printf("Choose an operation(choose a number):\n 1. product\n 2. division\n 3. difference\n 4. addition\n: ");
    scanf("%d", &choice);
    prodf = product(a, b);
    divf = division(a, b);
    diff = difference(a, b);
    addf = addition(a, b);

    switch(choice)
    {
        case 1:
        printf("The product is %d\n", prodf);
        break;
        case 2:
        printf("The division is %.2f\n", divf);
        break;
        case 3:
        printf("The difference is %d\n", diff);
        break;
        case 4:
        printf("The sum is %d\n", addf);
        break;
    }
    printf("--------------------------------------\n");
    printf("Come back for more calculations\n");
    printf("--------------------------------------\n");

    return 0;
}

int product(int a, int b)
{
    return a * b;
}

float division(float a, float b)
{
    return a / b;
}

int difference(int a, int b)
{
    return a - b;
}

int addition(int a, int b)
{
    return a + b;
}