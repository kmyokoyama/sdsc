#ifndef _LINKED_LIST_ITERATOR_H_
#define _LINKED_LIST_ITERATOR_H_

#include <linked_list.h>

LINKED_LIST_ITERATOR linked_list_iterator_create(const LINKED_LIST *linked_list);
void linked_list_iterator_next(LINKED_LIST_ITERATOR *it);
LINKED_LIST_DATA linked_list_read_data(LINKED_LIST_ITERATOR *it);

#endif //_LINKED_LIST_ITERATOR_H_
