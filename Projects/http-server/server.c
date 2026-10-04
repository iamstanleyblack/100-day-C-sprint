#include<stdio.h> // i use this for printf(), perror(), fopen()and getc()
#include<unistd.h> // i use this for close(),
#include<sys/socket.h> // i use this for socket(), bind(), accept(), recv(), send(), setsockopt() - which are essential functions for network programminga
#include<stdlib.h> // i use this for exit()
#include<sys/types.h> // i use this for socklen_t
// #include<sys/socket.h>
#include<netdb.h> // i use this for struct addrinfo getinfo()
#include<string.h> // i use this for memset(), strncmp(), and strlen()
/*
                    YOUR PROGRAM

socket()
   │
   │ creates
   ▼
sockfd
   │
   │
   │ getaddrinfo()
   │
   ▼
res
   │
   │ contains
   ▼
address information
   │
   │
   │ bind(sockfd, address, address_size)
   ▼
┌─────────────────────────┐
│      My socket          │
│  127.0.0.1 : 8080       │
└─────────────────────────┘
*/
//***********************//
// WHAT THIS PROGRAM DOES//
//***********************//
/*
it createes a socket, the tcp socket binds to port 8080 on local host. program waits for browser, GET / accept() receives HTTP request, reads the index.html then sends HTTP response, Browser displays webpage

NO APACHE
NO NGINX
NO NODE.JS
NO FLASK
JUST C

*/

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // the socket connecton a file still
    // A socket is an endpoint for network communicaiton
    // its like a file descriptor representing a communication channel,
    // int sockfd is the variable for this socket descriptro
    // AF_INET is for us to use the IPv4 addressing, the one for using ipv6 is called AF_INET6.
    //AF_INET is the address family
    //SOCK_STREAM is the stream socet, normally TCP
    // 0 - This lets the OS choose teh appropriate protocol for that socket type
    // socket() asks the OS to create a socket and returns a file descriptor identifying it
    // SOCK_STREAM is for us to uset he tcp protocol, for UDP it would be SOCK_DGRAM
    // socket() returns a number which is stored in the sockfd. The number identifies the socket to the operating system, which I'll then be using later for my calls(like in bind(sockfd...), listen(sockfd...), accept(sockfd...),))
    if (sockfd < 0)// A socket() usually returns a negative value/file descriptor when it fails, so if it fails, sockfd will be less than zero, and we'll ge t a perror("Socket error");
    // the number socket() returns which we refer to with sockfd is not necessarily the socket number in some networking sense. Its is a file descriptor
    {
        perror("Socket error");
        exit(-1);
    }
    int yes=1; // creating an integer variable. Then we'll give this value to setsockopt()
    //char yes='1'; // Solaris users use tihis
    // To solve the problem of "Address already in use" error message and allow reuse
    /* 
    Imagine this, when I run my server, then the brower startes listen for localhost:8080, then I stop the server on teh terminal with ctrl + C, tehn  I run he server again ./server. I will get th error "Address already in use"
    BUT WHYYYY???
    This is because TCP connections have states, and after a conenction closes, the old connection or address information can remain around temporarily. thsi si annoying because now when Im developing my server I will ahve to constantly run start-> test->stop->modify->start->test->stop...
    so S_REUSEADDR teslls the OS to allow me reuse the local adress
    */
    /*
    The setsockopt() function allows me to configure an option on my socket.
    set + sock + opt -> set socket option - this tells the OS to chane an option onthis socket option 
    sockfd -> the particular socket we are trying to configure. 
    SOL_SOCKET -> telling OS the oprint belons to the ** socket level**

    */
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes);
    struct addrinfo hint, *res;
    hint.ai_family = AF_INET;
    hint.ai_socktype = SOCK_STREAM;
    hint.ai_flags = AI_PASSIVE;
    getaddrinfo(NULL, "8080", &hint, &res);
// NULL means this is a server and we have specified iT WITH(AI_PASSIVE), 8080IS THE PORT number. It is a strin and not an integer, that is how getaddrinfo() accepts tit. &hint is the memory address for hint,&res js anothe rmemory address for res.
/*
                 getaddrinfo()
                      │
          ┌───────────┴───────────┐
          │                       │
       INPUT                    OUTPUT
          │                       │
        hint                    res
          │                       │
 "IPv4 + TCP + passive"     address information

 "bind attaches the socket to a specific local IP address and port
 getaddrinfo() - I am creating a server
 I want an IPv4 addrress,
 for a TCP socket
 and I intend to uset teh result for binding" - Basically what hint does.
*/
    int bind_result = bind(sockfd, res->ai_addr,res->ai_addrlen);// sizeof(struct sockaddr));
    //The '->' operator is used when we have a pointer to a structure and we awnat to access one of its members

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
    // while (1)
    // {

    int num_bytes = recv(new_fd, received_request, max_len, 0);
    // printf("num_bytes = %d\n", num_bytes);
    // for (int i = 0; i < num_bytes; ++i){
    //     putchar(received_request[i]);
    // }
    // printf(received_request);
    if (strncmp(received_request, "GET", 3) == 0)
    {
        printf("Received HTTP GET request!\n.");
        
        // Respnd to the HTTP GET request
        char *status_line = "HTTP/1.1 200 OK\r\n";
        int sent_bytes = send(new_fd, status_line, strlen(status_line), 0);
        printf("sent_bytes = %d\n", sent_bytes);
        char *headers = "Content-Type: text/html\r\n\r\n";  
            // "Content-Length: 10\r\n";
        sent_bytes = send(new_fd, headers, strlen(headers), 0);
        printf("sent_bytes = %d\n", sent_bytes);
        FILE *index_file = fopen("index.html", "r");
        char c;
        while( (c = getc(index_file)) != EOF){
            sent_bytes = send(new_fd, &c, 1, 0);//strlen(response_body), 0);
        }
        // char *response_body = "<h1>Stanley Black</h1>\r\n";
        // sent_bytes = send(new_fd, response_body, strlen(response_body), 0);


        // printaf("sent_bytes = %d\n", sent_bytes);
        // // int response_length = 100000;
        // // char response[response_length];
        // // int num_bytes = send(new_fd, response, int len, int flags);
    }
    else{
    printf("Received Non-GET request. Ignoring ...\n");
    close(new_fd);
    close(sockfd);
    exit(-1);
}
close(new_fd);
close(sockfd);
}
     
// }