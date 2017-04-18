#include <stdlib.h>
#include <deque_iterator.h>

DEQUE_ITERATOR deque_iterator_create(const DEQUE *deque) {
    DEQUE_ITERATOR it;

    it.node = deque->head;
    it.position = 0;

    if(it.node == NULL)
        it.has_next = 0;
    else
        it.has_next = 1;

    return it;
}

void deque_iterator_next(DEQUE_ITERATOR *it) {
    it->node = it->node->next;

    if(it->node == NULL)
        it->has_next = 0;
    else
        it->has_next = 1;
}

DEQUE_DATA deque_read_data(DEQUE_ITERATOR *it) {
    DEQUE_DATA data = it->node->data;

    deque_iterator_next(it);

    return data;
}
