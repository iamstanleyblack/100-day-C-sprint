#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
/* reads /flag.txt — works because the service runs as `ctf` via socat */
static void get_flag(void) {
    FILE *f = fopen("/flag.txt", "r");
    if (!f) { printf("flag file missing — contact support\n"); return; }
    printf("You win! ");
    int ch;
    while ((ch = fgetc(f)) != EOF) putchar(ch);
    fclose(f);
    fflush(stdout);
}
 
int main(void) {
    volatile int win = 0;   /* overflow this from 0 to anything non-zero */
    char buffer[8];          /* only 8 bytes of space */
 
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin,  NULL, _IONBF, 0);
 
    printf("What do you say? ");
    read(0, buffer, 100);          
 
    if (win != 0) {
        get_flag();
    } else {
        printf("Access denied.\n");
    }
    return 0;
}
