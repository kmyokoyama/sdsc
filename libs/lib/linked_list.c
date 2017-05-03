#include <stdlib.h>
#include <linked_list.h>

LINKED_LIST *linked_list_create() {
    LINKED_LIST *linked_list;

    linked_list = (LINKED_LIST *) malloc(sizeof(LINKED_LIST));

    if (linked_list == NULL) {
        return NULL;
    }

    linked_list->head = NULL;
    linked_list->tail = NULL;
    linked_list->size = 0;

    return linked_list;
}

unsigned int linked_list_insert_first(LINKED_LIST *linked_list, const LINKED_LIST_DATA data) {
    LINKED_LIST_NODE *new_node;

    new_node = (LINKED_LIST_NODE *) malloc(sizeof(LINKED_LIST_NODE));

    if (new_node == NULL) {
        return 0;
    }

    new_node->data = data;
    new_node->previous = NULL;
    new_node->next = linked_list->head;

    if(linked_list->size == 0) {
        linked_list->tail = new_node;
    }
    else {
        linked_list->head->previous = new_node;
    }

    linked_list->head = new_node;

    linked_list->size++;

    return linked_list->size;
}

LINKED_LIST_DATA linked_list_remove_first(LINKED_LIST *linked_list) {
    if(linked_list->size == 0) {
        return NULL;
    }

    LINKED_LIST_NODE *first = linked_list->head;
    LINKED_LIST_DATA data = first->data;

    linked_list->head = first->next;

    if(linked_list->head == NULL) {
        linked_list->tail = NULL;
    }
    else {
        linked_list->head->previous = NULL;
    }

    free(first);
    linked_list->size--;

    return data;
}

unsigned int linked_list_insert_last(LINKED_LIST *linked_list, const LINKED_LIST_DATA data) {
    LINKED_LIST_NODE *new_node;

    new_node = (LINKED_LIST_NODE *) malloc(sizeof(LINKED_LIST_NODE));

    if (new_node == NULL) {
        return 0;
    }

    new_node->data = data;
    new_node->previous = linked_list->tail;
    new_node->next = NULL;

    if(linked_list->size == 0) {
        linked_list->head = new_node;
    }
    else {
        linked_list->tail->next = new_node;
    }

    linked_list->tail = new_node;

    linked_list->size++;

    return linked_list->size;
}

LINKED_LIST_DATA linked_list_remove_last(LINKED_LIST *linked_list) {
    if(linked_list->size == 0) {
        return NULL;
    }

    LINKED_LIST_NODE *last = linked_list->tail;
    LINKED_LIST_DATA data = last->data;

    linked_list->tail = last->previous;

    if(linked_list->tail == NULL) {
        linked_list->head = NULL;
    }
    else {
        linked_list->tail->next = NULL;
    }

    free(last);
    linked_list->size--;

    return data;
}

unsigned int linked_list_insert_index(LINKED_LIST *linked_list, int index, const LINKED_LIST_DATA data) {
    if((index < 0) || (index > linked_list->size)) {
        return 0;
    }

    if(index == 0) {
        return linked_list_insert_first(linked_list, data);
    }
    if(index == linked_list->size) {
        return linked_list_insert_last(linked_list, data);
    }

    LINKED_LIST_NODE *current = linked_list->head;
    
    int i = 0;
    for(i = 0; i < index-1; i++) {
        current = current->next;
    }

    LINKED_LIST_NODE *new_node;
    new_node = (LINKED_LIST_NODE *) malloc(sizeof(LINKED_LIST_NODE));

    if (new_node == NULL) {
        return 0;
    }

    new_node->data = data;
    new_node->previous = current;
    new_node->next = current->next;
    current->next->previous = new_node;
    current->next = new_node;

    linked_list->size++;

    return linked_list->size;
}

LINKED_LIST_DATA linked_list_remove_index(LINKED_LIST *linked_list, int index) {
    if(linked_list->size == 0) {
        return NULL;
    }

    if((index < 0) || (index > linked_list->size)) {
        return NULL;
    }

    if(index == 0) {
        linked_list_remove_first(linked_list);
        return NULL;
    }
    if(index == linked_list->size) {
        linked_list_remove_last(linked_list);
        return NULL;
    }

    LINKED_LIST_NODE *current = linked_list->head;

    int i = 0;
    for(i = 0; i < index; i++) {
        current = current->next;
    }

    LINKED_LIST_DATA data = current->data;

    current->previous->next = current->next;
    current->next->previous = current->previous;

    free(current);

    linked_list->size--;

    return data;
}

LINKED_LIST *linked_list_copy(const LINKED_LIST *linked_list_src) {
    LINKED_LIST *linked_list_dst;
    linked_list_dst = linked_list_create();

    LINKED_LIST_NODE *current;

    for(current = linked_list_src->head;
        current != NULL;
        current = current->next) {
        LINKED_LIST_DATA data_current = current->data;
        linked_list_insert_last(linked_list_dst, data_current);
    }

    return linked_list_dst;
}

unsigned int linked_list_size(const LINKED_LIST *linked_list) {
    return linked_list->size;
}

int linked_list_index_first(const LINKED_LIST *linked_list, const LINKED_LIST_DATA data) {
    LINKED_LIST_NODE *current = linked_list->head;
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

void linked_list_remove_duplicated(LINKED_LIST *linked_list) {
    LINKED_LIST_NODE *current = linked_list->tail;
    int i = linked_list->size - 1;

    while(current != NULL) {
        int first;
        while((first = linked_list_index_first(linked_list, current->data)) != i) {
            linked_list_remove_index(linked_list, first);
            i--;
        }

        current = current->previous;
        i--;
    }
}

void linked_list_swap(LINKED_LIST *linked_list, int index_src, int index_dst) {
    if(index_src >= linked_list->size ||
       index_dst >= linked_list->size) {
        return;
    }

    LINKED_LIST_NODE *src = NULL;
    LINKED_LIST_NODE *dst = NULL;
    
    LINKED_LIST_NODE *current = linked_list->head;
    int i = 0;
    for(i = 0; i < linked_list->size; i++) {
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

    LINKED_LIST_DATA data_tmp = src->data;
    src->data = dst->data;
    dst->data = data_tmp;
}

void linked_list_reverse(LINKED_LIST *linked_list) {
    LINKED_LIST_NODE *current = linked_list->tail;
    while(current != NULL) {
        LINKED_LIST_NODE *previous_tmp = current->previous;
        current->previous = current->next;
        current->next = previous_tmp;
        
        current = current->next;
    }

    LINKED_LIST_NODE *head_tmp = linked_list->head;
    linked_list->head = linked_list->tail;
    linked_list->tail = head_tmp;
}

void linked_list_destroy(LINKED_LIST **ref_linked_list) {
    if((*ref_linked_list)->size == 0) {
        free(*ref_linked_list);
        *ref_linked_list = NULL;

        return;
    }

    LINKED_LIST_NODE *current;
    current = (*ref_linked_list)->head;

    while(current != NULL) {
        LINKED_LIST_NODE *tmp = current->next;
        free(current);
        current = tmp;
    }

    free(*ref_linked_list);
    *ref_linked_list = NULL;
}
