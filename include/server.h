#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "sys/socket.h"
#include "sys/types.h"
#include "netdb.h"
#include "errno.h"

typedef struct client_info_struct {
	pthread_t cli_thread; 
	int cli_socket; 
} client_info; 

int create_server(char* port);

int server_listen(int server_socket);

void server_accept_main_loop(int server_socket);

#endif