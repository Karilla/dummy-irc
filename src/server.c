#include <server.h>
#include <client.h>
#include <pthread.h>

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

    struct addrinfo* iter;

	for (iter = addr; iter != NULL; iter = iter->ai_next) {							// try all sockets
		socket_fd = socket(iter->ai_family, iter->ai_socktype, iter->ai_protocol);

		if (socket_fd < 0)															// this one failed, try next
			continue;

		if (bind(socket_fd, iter->ai_addr, iter->ai_addrlen) == 0)					// success, use it
			break;

		fprintf(stderr, "Error calling bind: %s\n", strerror(errno));

		close(socket_fd);															// socket failed to bind, so this should be closed
	}

    return socket_fd;

}

int server_listen(int server_socket)
{
    printf("Listening...\n");
    return listen(server_socket,1024);
}

void server_accept_main_loop(int server_socket)
{
    int client_socket = 2;
    client_info* new_client;
    struct sockaddr client_addr;
    socklen_t client_size = sizeof(struct sockaddr);

    memset(&client_addr,0,sizeof(struct sockaddr));

    for(;;)
    {

        client_socket = accept(server_socket,&client_addr,&client_size);

        if(client_socket < 0)
        {
            fprintf(stderr,"Client connection failed\n");
            continue;
        }

        printf("New connection...\n");

        new_client = (client_info*)malloc(sizeof(client_info));
        new_client->cli_socket = client_socket;
        printf("Connecting client on socket %i\n", client_socket);
        pthread_create(&(new_client->cli_thread), NULL, (void*(*)(void*))client_connect, (void*)(new_client));
    }

    
}

