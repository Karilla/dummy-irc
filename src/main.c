#include <stdio.h>
#include <server.h>

int main()
{
    int server_socket;

    printf("Starting server...\n");

    server_socket = create_server("6666");

    printf("Server Started...\n");

    return 0;
}