#include <stdlib.h>
#include <deque.h>

DEQUE *deque_create() {
    DEQUE *deque;

    deque = (DEQUE *) malloc(sizeof(DEQUE));

    if (deque == NULL) {
        return NULL;
    }

    deque->head = NULL;
    deque->tail = NULL;
    deque->size = 0;

    return deque;
}

unsigned int deque_insert_first(DEQUE *deque, const DEQUE_DATA data) {
    DEQUE_NODE *new_node;

    new_node = (DEQUE_NODE *) malloc(sizeof(DEQUE_NODE));

    if (new_node == NULL) {
        return 0;
    }

    new_node->data = data;
    new_node->previous = NULL;
    new_node->next = deque->head;

    if(deque->size == 0) {
        deque->tail = new_node;
    }
    else {
        deque->head->previous = new_node;
    }

    deque->head = new_node;

    deque->size++;

    return deque->size;
}

DEQUE_DATA deque_remove_first(DEQUE *deque) {
    if(deque->size == 0) {
        return NULL;
    }

    DEQUE_NODE *first = deque->head;
    DEQUE_DATA data = first->data;

    deque->head = first->next;

    if(deque->head == NULL) {
        deque->tail = NULL;
    }
    else {
        deque->head->previous = NULL;
    }

    free(first);
    deque->size--;

    return data;
}

unsigned int deque_insert_last(DEQUE *deque, const DEQUE_DATA data) {
    DEQUE_NODE *new_node;

    new_node = (DEQUE_NODE *) malloc(sizeof(DEQUE_NODE));

    if (new_node == NULL) {
        return 0;
    }

    new_node->data = data;
    new_node->previous = deque->tail;
    new_node->next = NULL;

    if(deque->size == 0) {
        deque->head = new_node;
    }
    else {
        deque->tail->next = new_node;
    }

    deque->tail = new_node;

    deque->size++;

    return deque->size;
}

DEQUE_DATA deque_remove_last(DEQUE *deque) {
    if(deque->size == 0) {
        return NULL;
    }

    DEQUE_NODE *last = deque->tail;
    DEQUE_DATA data = last->data;

    deque->tail = last->previous;

    if(deque->tail == NULL) {
        deque->head = NULL;
    }
    else {
        deque->tail->next = NULL;
    }

    free(last);
    deque->size--;

    return data;
}

DEQUE *deque_copy(const DEQUE *deque_src) {
    DEQUE *deque_dst;
    deque_dst = deque_create();

    DEQUE_NODE *current;

    for(current = deque_src->head;
        current != NULL;
        current = current->next) {
        DEQUE_DATA data_current = current->data;
        deque_insert_last(deque_dst, data_current);
    }

    return deque_dst;
}

unsigned int deque_size(const DEQUE *deque) {
    return deque->size;
}

int deque_index_first(const DEQUE *deque, const DEQUE_DATA data) {
    DEQUE_NODE *current = deque->head;
    int i = 0;

    while(current != NULL) {
        if(current->data == data) {
            return i;
        }
        current = current->next;
        i++;
    }

    return -1;
}

void deque_destroy(DEQUE **ref_deque) {
    if((*ref_deque)->size == 0) {
        free(*ref_deque);
        *ref_deque = NULL;

        return;
    }

    DEQUE_NODE *current;
    current = (*ref_deque)->head;

    while(current != NULL) {
        DEQUE_NODE *tmp = current->next;
        free(current);
        current = tmp;
    }

    free(*ref_deque);
    *ref_deque = NULL;
}
