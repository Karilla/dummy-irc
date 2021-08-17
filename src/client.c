
#include <server.h>
#include <client.h>
#include <pthread.h>
#include <string.h>
#include <regex.h>
void client_list_init()
{
    client_list = create_list();
}


void client_connect(client_info* cli)
{
    char buffer[4000];

    recv(cli->cli_socket,buffer,4000,0);
    fwrite(buffer, 4000, 1, stdout);

    printf("New thread started...");
}

