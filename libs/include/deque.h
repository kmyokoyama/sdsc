#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <common.h>

typedef _DATA DEQUE_DATA;

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
DEQUE *deque_copy(const DEQUE *deque_src);
unsigned int deque_size(const DEQUE *deque);
void deque_destroy(DEQUE **ref_deque);

#endif //_DEQUE_H_
