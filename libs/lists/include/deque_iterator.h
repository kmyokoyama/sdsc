#ifndef _DEQUE_ITERATOR_H_
#define _DEQUE_ITERATOR_H_

#include <deque.h>

DEQUE_ITERATOR deque_iterator_create(DEQUE *deque);
void deque_iterator_next(DEQUE_ITERATOR *it);
DEQUE_DATA deque_read_data(DEQUE_ITERATOR *it);

#endif //_DEQUE_ITERATOR_H_
