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

unsigned int deque_insert_index(DEQUE *deque, int index, const DEQUE_DATA data) {
    if((index < 0) || (index > deque->size)) {
        return 0;
    }

    if(index == 0) {
        return deque_insert_first(deque, data);
    }
    if(index == deque->size) {
        return deque_insert_last(deque, data);
    }

    DEQUE_NODE *current = deque->head;
    
    int i = 0;
    for(i = 0; i < index-1; i++) {
        current = current->next;
    }

    DEQUE_NODE *new_node;
    new_node = (DEQUE_NODE *) malloc(sizeof(DEQUE_NODE));

    if (new_node == NULL) {
        return 0;
    }

    new_node->data = data;
    new_node->previous = current;
    new_node->next = current->next;
    current->next->previous = new_node;
    current->next = new_node;

    deque->size++;

    return deque->size;
}

DEQUE_DATA deque_remove_index(DEQUE *deque, int index) {
    if(deque->size == 0) {
        return NULL;
    }

    if((index < 0) || (index > deque->size)) {
        return NULL;
    }

    if(index == 0) {
        deque_remove_first(deque);
        return NULL;
    }
    if(index == deque->size) {
        deque_remove_last(deque);
        return NULL;
    }

    DEQUE_NODE *current = deque->head;

    int i = 0;
    for(i = 0; i < index; i++) {
        current = current->next;
    }

    DEQUE_DATA data = current->data;

    current->previous->next = current->next;
    current->next->previous = current->previous;

    free(current);

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

void deque_remove_duplicated(DEQUE *deque) {
    DEQUE_NODE *current = deque->tail;
    int i = deque->size - 1;

    while(current != NULL) {
        int first;
        while((first = deque_index_first(deque, current->data)) != i) {
            deque_remove_index(deque, first);
            i--;
        }

        current = current->previous;
        i--;
    }
}

void deque_swap(DEQUE *deque, int index_src, int index_dst) {
    if(index_src >= deque->size ||
       index_dst >= deque->size) {
        return;
    }

    DEQUE_NODE *src = NULL;
    DEQUE_NODE *dst = NULL;
    
    DEQUE_NODE *current = deque->head;
    int i = 0;
    for(i = 0; i < deque->size; i++) {
        if(i == index_src) {
            src = current;
        }
        if(i == index_dst) {
            dst = current;
        }

        if(src != NULL && dst != NULL)
            break;

        current = current->next;
    }

    DEQUE_DATA data_tmp = src->data;
    src->data = dst->data;
    dst->data = data_tmp;
}

void deque_reverse(DEQUE *deque) {
    DEQUE_NODE *current = deque->tail;
    while(current != NULL) {
        DEQUE_NODE *previous_tmp = current->previous;
        current->previous = current->next;
        current->next = previous_tmp;
        
        current = current->next;
    }

    DEQUE_NODE *head_tmp = deque->head;
    deque->head = deque->tail;
    deque->tail = head_tmp;
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
