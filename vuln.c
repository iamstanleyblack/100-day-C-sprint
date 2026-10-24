#include<stdio.h> // to use printf()
#include<string.h> // to use strcpy()

void greet(char *input){ // the function called greet whcih doesn't return anything receives a pointer to a string. 

    char buffer[16]; // reserve 16 bytes of space on the stack and call it buffer. The vulnerability is that C does not check wheterh I wrote more than 16 bytes

    strcpy(buffer, input); // strcpy copies the text from the input into the buffer byte by byte until it hits a null terminator but never checks whter the buffer is big enought


    printf("Hello, %s!\n", buffer);

}

int main(int argc, char *argv[]){ // argc is the argument count whtich checks how many wordds I typed ont eh comand line, includeing the program name itself. argv is an array of those awords as strings and so argv[0] is the program name, and argv[1] is my first argument

    if(argc < 2) {
        printf("Usage: %s <name>\n", argv[0]); 
        return 1;
        // This is a safety check , if I did not pass a name(so argc is les than 2) it print usage instructions and quei with exit code 1meaning error. 
}
        greet(argv[1]); //
        printf("Returned safely.\n");
        return 0;
    

}