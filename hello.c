/* Hello world program*/

#include<stdio.h>
/*The #include is called a preprocessor directive. It tells the C processor to pull the contents of another file and insert it into the code right there

THere are two stages to compilation
1. the precessor
2. the compiler
 Anything that starts with a pound sign or octothorpe (#) is something the preprocessor operates on before the compiler even gets started.
once the preprocessor has finished preprocessing,  the compiler begins the compilation where the code is translated into machine language/assembly
The <stdio.h> is actually callled theh standard input output or standard i/o which gives us access to a bunch of I/O functionality such as printf(). If we try to do printf without including the #include<stdio.h> at the top then the compiler wouldn't know what to do.

*/
// the main() below is the function called the moment we execute our code. 
// even if we define other functions outside of this main we still have to call that function inside of this main function for it to actually be compiled
//whats a function you ask? This is just a block of code that you can define once/write once and then instead of writing the whole lines of code again and again, you just call/use the function name instead.
// to execute the code on a unix-like platform, use the commad  below to compile the code
// gcc -o hello hello.c or gcc hello.c -o hello
// and then to execute the compiled program, use ./hello(or the name of your program)
// the -o just means 'output to this file' so the file we want to output to is called hello in this case
int main() {
    printf("Hello World"); // This is where the program actually runs
    // The printf is the command to actually show us 

    return 0;
}
/*This is a comment and will be ignored completely by the compiler*/