#include <stdio.h>
#include <server.h>

int create_server(char* port)
{
    struct addrinfo hints;
    struct addrinfo* addr;  
    int socket_fd;

    memset(&hints,0,sizeof(struct addrinfo));

    hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	hints.ai_protocol = 0;
	hints.ai_canonname = NULL;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;

    getaddrinfo(NULL,port,&hints,&addr);

    socket_fd = socket(addr->ai_family,addr->ai_socktype,addr->ai_protocol);

    if(socket < 0)
    {
        fprintf(stderr,"Error creating the socket");
        exit(EXIT_FAILURE);
    }

    if(bind(socket_fd,addr->ai_addr,addr->ai_addrlen) < 0)
    {
        fprintf(stderr,"Cannot bind the socket\n");
        exit(EXIT_FAILURE);
    }

    return socket_fd;

}

void server_accept_main_loop(int server_socket)
{
    int client_socket;
    client_info* new_client;
    struct sockaddr client_addr;
    socklen_t client_size = sizeof(struct sockaddr);

    memset(&client_addr,0,sizeof(struct sockaddr));

    for(;;)
    {

        if(client_socket < 0)
        {
            fprintf(stderr,"Client connection failed");
            exit(EXIT_FAILURE);
        }

        client_socket = accept(server_socket,&client_addr,client_size);


        new_client = (client_info*)malloc(sizeof(client_info));
        new_client->client_socket = client_socket;
    }

    
}

