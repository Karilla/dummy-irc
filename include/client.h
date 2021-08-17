#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <stdbool.h>
#include <chainedlist.h>
#include <pthread.h>

typedef struct client
{
    char* nickname;
    pthread_t client_thread;
    int client_socket;
    pthread_mutex_t client_sock_mutex;
}client;

list* client_list;

void client_list_init();

void client_connect(client_info* cli);

#endif