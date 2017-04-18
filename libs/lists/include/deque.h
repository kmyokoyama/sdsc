#ifndef _DEQUE_H_
#define _DEQUE_H_

typedef char* DEQUE_DATA;

typedef struct deque_node {
    DEQUE_DATA data;
    struct deque_node *next;
    struct deque_node *previous;
} DEQUE_NODE;

typedef struct deque {
    DEQUE_NODE *head;
    DEQUE_NODE *tail;
    unsigned int size;
} DEQUE;

typedef struct iterator_deque {
    DEQUE_NODE *node;
    int position;
    int has_next;
} DEQUE_ITERATOR;

DEQUE *deque_create(); 
unsigned int deque_insert_first(DEQUE *deque, const DEQUE_DATA data);
DEQUE_DATA deque_remove_first(DEQUE *deque);
unsigned int deque_insert_last(DEQUE *deque, const DEQUE_DATA data);
DEQUE_DATA deque_remove_last(DEQUE *deque);
unsigned int deque_insert_index(DEQUE *deque, int index, const DEQUE_DATA data);
DEQUE_DATA deque_remove_index(DEQUE *deque, int index);
DEQUE *deque_copy(const DEQUE *deque_src);
unsigned int deque_size(const DEQUE *deque);
int deque_index_first(const DEQUE *deque, const DEQUE_DATA data);
void deque_remove_duplicated(DEQUE *deque);
void deque_swap(DEQUE *deque, int index_src, int index_dst);
void deque_reverse(DEQUE *deque);
void deque_destroy(DEQUE **ref_deque);

#endif //_DEQUE_H_
