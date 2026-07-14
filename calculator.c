//Variables - This is a name given to a certain value. it is like a container or a label used to identify the content stored in a certain memory location
// Data types in C include
/* Integer e.g. 23423 denoted as int
    Floating point e.g. 3.14159 denoted as float
    Character e.g. 'c' denoted as char
    String e.g. "Hello World!" denoted as char *
NB:/- Before you can use a variable, you have to declare that variable and tell C what type the variable holds

*/

// To use  variable in C, we first have to declare it, then initialize it by assigning a value to it. When declaring we have to explicitly state the data type of the variable

// example1: int varName1 = 23(the value you have assigned);
// example2: float varName2 = 3.45(the flaot value);
// integer holds signed integers like -3, -2, 0, 1, 2, 10
// float holds signed floating point numbers like -3.1416

// Uninitialized variables have indeterminate values adn so a variable has to be initialized or else you must assume thy contain some nonesense number


// Always initialize a variable explicitly to some value before you use them

// int i;
// i = 2; Here we are assigning the value 2 into the variable i
// After we have assigned a value to a variable and now we want to print it, we do that by passing two arguments to the printf() function and those two variables are; the first argument is a string that describes what to print and how to print it(called format string) and the second is the value to print , which is whatever name we have provided
// For example int i = 2; float f = 3.14; char *s = "Hello World"; To  print this to the screeen, we use the following format 'printf("%s i=%d and f = %f\n", s, i, f); The output for this will be 'Hello world i = 2 and f = 3.14. The \n at the end is a new line character which makes and extra spaace int eh output so t he cursor moves to the next line

/*Operators and Expressions in C
i = i + 3; this can aslo be written as i += 3;
i = i - 4; this can also be written as i -= 4;
i = i * 5; this can aslo be written as i *= 5;
i = i / 3; thsi can aslo be written as i /= 3
i = i % 2; thsi can aslo be written as i %= 2;
*/

// Technically just one bit of a char is used to represent the bool , so it can either be zero or one.

// C also includes the ternary operator. This is an expression whose value depends on the result of a conditional embedded in it
/* if x > 10, add 17 to y. Othrwise add 37 to y
Using a ternary operator, thsi can be written as: y += x > 10? 17: 37;
 This expression can be written as:
 if(x > 10)
 y = y + 17;
 else:
 y = y + 37
 
 Pre- and Post Increment and Decrement
 i++;
 i--;
 or 
 i +=1;
 i -=1;
 or
 ++i;
 --i;
 Comma Operator - ths is an uncommonly used way to separate expressions that will run from left to right
x = 10, y = 20; you can also just separate them using a semicolon x = 10; y = 20; but you should know tht these are two different things. The latter is two separate expressions while the former is a single expressions. Withe the comma, the value of the coma expression is th evlue of the rightmost expresision
x = (1, 2, 3); this will prit 3 because 3 is the rightmost int the comma list. This is not so clearn however, because in a for loop we use a for loop to do multiple thing in each section of the statement
 */

 /*
 Conditional Operators
 a == b; is true if a is equiv to b
 a != b; is true if a is not equiv to b
 a < b; is true if a is less than b
 a > b; is true if a is greater than b
 a <= b; is true if a is less than or equiv to b
 a >= b; is true if a is greter than or equiv to b
 NB:/- Do not mix up assignment operator '=' and comparison operator '=='
 
 
 The 'SIZEOF operator
 this operator tells you the size (in bytes) that a particular variable or data type uses in memory
 */


 #include<stdio.h>
 #include<stdbool.h>
 int main(){
    int first = 0;
    int second = 4;
    printf("%d\n", first < second); // Since first is less than second, This evaluates to true (1)

    if(first < second){
        printf("First is smaller than second\n");
    }
    else if(first > second){
        printf("First is greater than second\n");
    }
    else{printf("First and Second are equal\n");
    }
    while(first < second){
        printf("First is less than second\n");
        first = first + 1;
        break;
    }
    printf("%zu is the size of the first value\n", sizeof(first));
    printf("%zu is the size of the second value\n", sizeof(second));
    printf("This is because both the values are integers and integers typically have a size of 4\n");
    printf("End of the program\n");
    return 0;
 }