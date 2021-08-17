#include <chainedlist.h>

node* create_node(void* data)
{
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

list* create_list()
{
    list* liste = (list*)malloc(sizeof(list));
    liste->head = NULL;
    return liste;
}