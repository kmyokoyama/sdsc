#include <stdlib.h>
#include <linked_list_iterator.h>

LINKED_LIST_ITERATOR linked_list_iterator_create(const LINKED_LIST *linked_list) {
    LINKED_LIST_ITERATOR it;

    it.node = linked_list->head;
    it.position = 0;

    if(it.node == NULL)
        it.has_next = 0;
    else
        it.has_next = 1;

    return it;
}

void linked_list_iterator_next(LINKED_LIST_ITERATOR *it) {
    it->node = it->node->next;

    if(it->node == NULL)
        it->has_next = 0;
    else
        it->has_next = 1;
}

LINKED_LIST_DATA linked_list_read_data(LINKED_LIST_ITERATOR *it) {
    LINKED_LIST_DATA data = it->node->data;

    linked_list_iterator_next(it);

    return data;
}
