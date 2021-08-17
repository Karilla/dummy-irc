#ifndef _CHAINEDLIST_H_
#define _CHAINEDLIST_H_

#include <stddef.h>

typedef struct node_struct node;

struct node_struct
{
    void* data;
    node* next;
};

typedef struct list
{
    node* head;
}list;

node* create_node(void* data);

list* create_list();

#endif