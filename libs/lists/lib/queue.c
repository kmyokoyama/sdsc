#include <stdlib.h>
#include <queue.h>

QUEUE *queue_create() {
    QUEUE *queue;

    queue = (QUEUE *) malloc(sizeof(QUEUE));

    if (queue == NULL) {
        return NULL;
    }

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

unsigned int queue_enqueue(QUEUE *queue, const QUEUE_DATA data) {
    QUEUE_NODE *new_node;

    new_node = (QUEUE_NODE *) malloc(sizeof(QUEUE_NODE));

    if (new_node == NULL) {
        return 0;
    }

    new_node->data = data;

    if(queue->size == 0) {
        new_node->next = queue->head;
        new_node->previous = queue->tail;
        queue->head = new_node;
    }
    else {
        new_node->next = queue->tail;
        new_node->previous = NULL;
        queue->tail->previous = new_node;
    }

    queue->tail = new_node;

    queue->size++;

    return queue->size;
}

QUEUE_DATA queue_dequeue(QUEUE *queue) {
    if(queue->size == 0) {
        return NULL;
    }

    QUEUE_NODE *first = queue->head;
    QUEUE_DATA data = first->data;

    queue->head = first->previous;

    if(queue->head == NULL) {
        queue->tail = NULL;
    }
    else {
        queue->head->next = NULL;
    }

    free(first);
    queue->size--;

    return data;
}

int queue_size(const QUEUE *queue) {
    return queue->size;
}

int queue_is_empty(const QUEUE *queue) {
    return (queue->size == 0 ? 1 : 0);
}

void queue_destroy(QUEUE **ref_queue) {
    if((*ref_queue)->size == 0) {
        free(*ref_queue);
        *ref_queue = NULL;

        return;
    }

    QUEUE_NODE *current;
    current = (*ref_queue)->tail;

    while(current != NULL) {
        QUEUE_NODE *tmp = current->next;
        free(current);
        current = tmp;
    }

    free(*ref_queue);
    *ref_queue = NULL;
}
