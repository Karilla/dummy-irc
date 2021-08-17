#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <pthread.h>

typedef struct Client
{
    char* nickname;
    pthread_t client_thread;
    int client_socket;
    pthread_mutex_t client_sock_mutex;
}Client;

#endif