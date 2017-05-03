#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef char* LINKED_LIST_DATA;

typedef struct linked_list_node {
    LINKED_LIST_DATA data;
    struct linked_list_node *next;
    struct linked_list_node *previous;
} LINKED_LIST_NODE;

typedef struct linked_list {
    LINKED_LIST_NODE *head;
    LINKED_LIST_NODE *tail;
    unsigned int size;
} LINKED_LIST;

typedef struct iterator_linked_list {
    LINKED_LIST_NODE *node;
    int position;
    int has_next;
} LINKED_LIST_ITERATOR;

LINKED_LIST *linked_list_create(); 
unsigned int linked_list_insert_first(LINKED_LIST *linked_list, const LINKED_LIST_DATA data);
LINKED_LIST_DATA linked_list_remove_first(LINKED_LIST *linked_list);
unsigned int linked_list_insert_last(LINKED_LIST *linked_list, const LINKED_LIST_DATA data);
LINKED_LIST_DATA linked_list_remove_last(LINKED_LIST *linked_list);
unsigned int linked_list_insert_index(LINKED_LIST *linked_list, int index, const LINKED_LIST_DATA data);
LINKED_LIST_DATA linked_list_remove_index(LINKED_LIST *linked_list, int index);
LINKED_LIST *linked_list_copy(const LINKED_LIST *linked_list_src);
unsigned int linked_list_size(const LINKED_LIST *linked_list);
int linked_list_index_first(const LINKED_LIST *linked_list, const LINKED_LIST_DATA data);
void linked_list_remove_duplicated(LINKED_LIST *linked_list);
void linked_list_swap(LINKED_LIST *linked_list, int index_src, int index_dst);
void linked_list_reverse(LINKED_LIST *linked_list);
void linked_list_destroy(LINKED_LIST **ref_linked_list);

#endif //_LINKED_LIST_H_
