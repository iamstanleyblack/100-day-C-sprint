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


#include<stdio.h>

int main()
{
    FILE *fp;   // Variable torepresent open file
    //fopen() returns the FILE* to us so we can use it later
    fp = fopen("hello.txt", "r");       // This opens the file for reading
    // The 'r' means 'open a text stream for reading'

    int c = fgetc(fp);       // This reads as ignle character
    // Why did we use int c instead of a char c?
    //fgetc() is to get a character from the stream
    printf("%c\n%c\n", c);      // This prints char to the stdout


    fclose(fp);         // This closes te file when done
    //We close the stream when we are done with it. All streams are automatically closed when the program exits but it is a good form and good housekeeping ie it is strongly advised to explicitly close any files yourself when done with it

    // FILE* keeps track of our position in the file so subsequent calls to fgetc() would get the next character in the file, and then next, until the end

    
}


//EOF
// There is a special character defined as a macro: EOF. THis is wha the fgetc() will return when the end of the file has been reached and you've attempted to read another character



#include<stdio.h>

int main()
{
    FILE *fp;   // Variable torepresent open file
    //fopen() returns the FILE* to us so we can use it later
    fp = fopen("hello.txt", "r");       // This opens the file for reading
    // The 'r' means 'open a text stream for reading'

    int c = fgetc(fp);       // This reads as ignle character
    // Why did we use int c instead of a char c?
    //fgetc() is to get a character from the stream
    int d = fgetc(fp);    
    int e = fgetc(fp);    
    int f = fgetc(fp);    
    int g = fgetc(fp);    
    int h = fgetc(fp);    
    int i = fgetc(fp);    
    int j = fgetc(fp);    
    int k = fgetc(fp);    
    int l = fgetc(fp); 
    int m = fgetc(fp);   
    printf("%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n", c, d, e, f, g, h, i, j, k, l, m);      // This prints char to the stdout


    fclose(fp);         // This closes te file when done
    //We close the stream when we are done with it. All streams are automatically closed when the program exits but it is a good form and good housekeeping ie it is strongly advised to explicitly close any files yourself when done with it

    // FILE* keeps track of our position in the file so subsequent calls to fgetc() would get the next character in the file, and then next, until the end

    
}

To read an entire line at once, we use fgets() instead of fgetc(). For arguments, it takes a pointer to a char to hold bytes, a maxumum number of bytes to read and a FILE* to read from. It wil return a NULL on end-of-file error. 


// Below is program to read a file line by line and to print the number first before priting the line


*/

#include<stdio.h>

int main()
{
    FILE *fp;
    char s[1024]; // THis is big enough for any line this program will encounter

    int linecounter = 0; // We initalize it to 0 at first

    fp = fopen("quote.txt", "r");
    while(fgets(s, sizeof s, fp) != NULL){
        printf("%d: %s", ++linecounter, s);
    }

    fclose(fp);
}