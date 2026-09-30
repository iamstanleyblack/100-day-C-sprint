#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // the socket connecton a file still
    if (sockfd < 0)
    {
        perror("Socket error");
        exit(-1);
    }

    struct addrinfo hint, *res;
    hint.ai_family = AF_INET;
    hint.ai_socktype = SOCK_STREAM;
    hint.ai_flags = AI_PASSIVE;
    getaddrinfo(NULL, "8080", &hint, &res);

    int bind_result = bind(sockfd, res->ai_addr,res->ai_addrlen);// sizeof(struct sockaddr));
    if (bind_result < 0)
    {
        perror("Bind error");
        exit(-1);
    }
    // printf("Bind result is: %d\n", bind_result);
    // struct addrinfo hints, *res;
    // memset(&hints, 0, sizeof hints);
    // hints.ai_family = AF_UNSPEC; // use IPv4 or IPv6, whichever
    // hints.ai_socktype = SOCK_STREAM;
    // hints.ai_flags = AI_PASSIVE; // this AI passive flag tells the program to bind to the IP of the host it is running on ,, this ai means sth arpanet sth

    // getaddrinfo(NULL, "3490", &hints, &res);

    // Listen for incoming connections
    int listen_result = listen(sockfd, 20);
    if (listen_result < 0)
    {
        perror("Listen error");
        exit(-1);
    }
    struct sockaddr_storage their_addr;
    socklen_t addr_size;
    int new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);// sizeof(their_adddr));

    // FILE *new_opened_fd = fopen(new_fd, "w");
    // while (1) // we make it run infinitely since servers run all the time

    // {
    //     // Some kind of request must be received here
    //     // printf("Waiting for request... \n");
    //     send(sockfd, "Hello Stanley", sizeof("Hello Stanley"), 0);
    //     // fputs("Hello", new_opened-fd);
    //     sleep(1);
    // }
    int max_len = 1000;
    char received_request[max_len];
    memset(received_request, 0, max_len); // Have to include string.h for this
    int num_bytes = recv(new_fd, received_request, max_len, 0);
    printf("num_bytes = %d\n", num_bytes);
    for (int i = 0; i < num_bytes; ++i){
        putchar(received_request[i]);
    }
    printf(received_request);
}