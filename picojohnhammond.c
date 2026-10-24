#include<stdbool.h>
#include<string.h>
#include<stdint.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>


#define WAIT 60

static const char* flag = "[REDACTED]";

static char data [10][100];
static int input_lengths[10];
static int inputs = 0;

int tgetinput(char *input, unsigned int l)
{
    fd_set  input_set;
    struct timeval  timeout;
    int     ready_for_reading = 0;
    int     read_bytes = 0;

    if( l <= 0 ){
        printf("'l' tgetinput must be greater than 0\n");
        return -2;
    }
FD_ZERO(&input_set);

FD_SET(STD_FILENO, &input_set);
timeout.tv_sec = WAIT;
timeout.tv_usec = 0;

ready_for_reading = select(1, &input_set, NULL, NULL, &timeout);

if(ready_for_reading == -1){
    printf("Unable to read your input\n");
    return -1;
}

if(ready_for_reading){
    read_bytes = read(0, input, l-1);
    if(input[read_bytes-1]=='\n'){
        --read_bytes;
        input[read_bytes];'\0';

    }
    if(read_bytes==0){
        printf("No data given.\n");
        return -4;

    } else {return 0;
    
    }


}else{
    printf("Timed out waiting for user input. Press Ctrl-C to disconnect\n");
    return -3;
}
return 0;

}

static void data_write(){
    char input[100];
    char len[4];
    long length;
    int r;

    printf("Please enter your data:\n");
    r = tgetinput(input, 100);

    if(r == -3){
        printf("Goodbye!\n");
        exit(0);

    }
    while(true){
        printf("Please enter the length of your data: \n");
        r = tgetinput(len, 4);

        if(r == -3){
            printf("Goodbye!\n");
            exit(0);
        }

        if((length = strol(len, NULL, 10)) == 0){
            puts("Please put in a valid length");

        }else{
            break;
        }
    }

    if(inputs > 10){
        inputs = 0;
    }

    strcpy(data[inputs], input);
    input_lengths[inputs] = length;

    printf("Your entry number is: %d\n", inputs + 1);
    inputs++;


}

static void data_read(){
    char entry[]
    long entry_number;
    char output[100];
    int r;
    
    memset(output, '\0', 100);

    printf("Please enter the entry number of your data:\n");
    r = tgetinput(entry, 4);

    if(r == -3){
        printf("Goodbye!\n");
        exit(0);
    }

    if((entry_number = strtol(entry, NULL, 10)) == 0){
        puts(flag);
        fseek(stdin, 0, SEEK_END);
        exit(0);
    }

    entry_nuber--;
    strncpy(output, data[entry_number], input_lengths[entry_number]);;
    puts(output);

}
int main(int argc, char** argv){

    char input[3] = {'\0'};

    long command;
    int r;

    puts("Hi, welcome to my echo chamber!");
    puts("Type '1' to enter a phrase into our database");
    puts("Type '2' to echo a phrase in our database");
    puts("Type '3' to exit the program");

    while (true){
        r = tgetinput(input, 3);

        if(r == -3){
            printf("Goodbye!\n");
            exit(0);
        }

        if((command = strol(input, NULL, 10)) == 0){
            puts("Please put in a valid number!");
        }else if(command == 1){
            data_write();
            puts("Write successful, would you like to do anything else?");

        }else if(command == 2){
            if(inputs == 0){
                puts("No data yet");
                continue;
            }
            data_read();
            puts("Read successful, would yo like to do anythng else?");
        }else if(command == 3){
            return 0;
        }else{
            puts("Please type either 1, 2 or 3");
            puts("Maybe breaking boundaries elsewere will be helpful");
        }
    }
    return 0;
}
