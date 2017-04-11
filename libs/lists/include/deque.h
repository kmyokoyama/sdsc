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
    int size;
} DEQUE;

typedef struct iterator_deque {
    DEQUE_NODE *node;
    int position;
    int has_next;
} DEQUE_ITERATOR;

DEQUE *deque_create(); 
void deque_insert_first(DEQUE *deque, DEQUE_DATA data);
DEQUE_DATA deque_remove_first(DEQUE *deque);
void deque_insert_last(DEQUE *deque, DEQUE_DATA data);
DEQUE_DATA deque_remove_last(DEQUE *deque);
void deque_insert_index(DEQUE *deque, int index, DEQUE_DATA data);
DEQUE_DATA deque_remove_index(DEQUE *deque, int index);
DEQUE *deque_copy(DEQUE *deque_src);
int deque_count(DEQUE *deque);
int deque_index_first(DEQUE *deque, DEQUE_DATA data);
void deque_remove_duplicated(DEQUE *deque);
void deque_swap(DEQUE *deque, int index_src, int index_dst);
void deque_reverse(DEQUE *deque);
void deque_destroy(DEQUE **ref_deque);

#endif //_DEQUE_H_
