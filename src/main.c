#include <stdio.h>
#include <server.h>
#include <client.h>

int main()
{
    int server_socket;

    client_list_init();

    printf("Starting server...\n");

    server_socket = create_server("6666");

    printf("Server Started...\n");

    server_listen(server_socket);

    server_accept_main_loop(server_socket);

    return 0;
}