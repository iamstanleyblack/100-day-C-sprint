/*
We do any kind of I/O operation in C through a piece of data that we get in the form of a FILE* type.
This FILE* holds all the information needed to communicate with the I/O subsystem about which file we have open and where we are in the file etc.
This is referred to as a stream i.e a strea of data from a file or from any source

FILE* name          Description
stdin       -       Standard  inpput, generally the keyboard by default
stdout      -       Standard output, generally the screen by default
stderr      -       Standard Error, generally the screen by default

// printf("Hello World!\n");
    AND
// fprintf(stdout, "Hello World!\n"); // this perfoms printf to a file
    ARE THE SAME
//Reading Text files
Streams are categorized into two:
1. text
2. binary
Text files are logicaly a sequence of lines separatd by newlines. To be portable, your input data should always end with a newline
NB:/- A general rule is that if you are able to edit the file in a regular text editor, it's a text file. Otherwise, it's binary.
How do we open a file and pput text in it? Check below :)
*/
#include<stdio.h>

int main()
{
    FILE *fp;   // Variable torepresent open file

    fp = fopen("hello.txt", r)
}