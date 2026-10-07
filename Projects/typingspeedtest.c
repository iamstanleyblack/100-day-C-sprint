#include<stdio.h>
#include<string.h>
#include<sys/time.h>
include <stdbool.h>
char *txt = "The quick brown fox jumps over the lazy dog";

typedef unsigned long int timestamp;

// Returns the current timestamp in microseconds
unsigned long int get_micros()
{
    struct timeval tv;

    int res = gettimeofday(&tv, NULL);
    if (res != 0)
    {
        perror("Getting time failed");
        return -1;
    }    
    unsigned long int timestamp = tv.tv_sec * 1000 * 1000 + tv.tv_usec;

    return timestamp;
}

// Returns the word count of a string
int get_word_count(char *str)
{
    int counter = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ' && inside_word == true)
        {
            //just entered space bewteen words
            inside_word = false;
        }
        else if (inside_word = false)
            {
                counter++;
                inside_word = true;
            }
        }
}

int main(int argc, char *argv[])


{
    printf("Type \"%s\":\n", txt);

    char typed_buffer[100];

    
    
    timestamp start_micros = get_micros();
    fgets(typed_buffer, sizeof(typed_buffer), stdin);

    int len = strlen(typed_buffer);
    typed_buffer[len-1] = '\0';

    timestamp end_micros = get_micros();
    timestamp micros = end_micros - start_micros;

    printf("User typed \"%s\"\n", typed_buffer);
    // printf("Start time was: %ld\n", tv.tv_sec);
    // printf("Start time was: %ld\n\tStart micros: %ld\n", start_time.tv_sec, tv.tv_usec);
    printf("Elapsed time: %ld microseconds\n", micros);
    // printf("Timestamp: %ld\n", micros);

    return 0;
}