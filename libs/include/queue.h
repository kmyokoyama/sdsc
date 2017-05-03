#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef char* QUEUE_DATA;

typedef struct queue_node {
    QUEUE_DATA data;
    struct queue_node *next;
    struct queue_node *previous;
} QUEUE_NODE;

typedef struct queue {
    QUEUE_NODE *head;
    QUEUE_NODE *tail;
    unsigned int size;
} QUEUE;

QUEUE *queue_create(); 
unsigned int queue_enqueue(QUEUE *queue, const QUEUE_DATA data);
QUEUE_DATA queue_dequeue(QUEUE *queue);
int queue_size(const QUEUE *queue);
int queue_is_empty(const QUEUE *queue);
void queue_destroy(QUEUE **ref_queue);

#endif //_QUEUE_H_
