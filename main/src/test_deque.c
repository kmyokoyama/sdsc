#include <stdio.h>
#include <lists.h>

int main(int argc, char **argv) {
    DEQUE *deque;

    deque = deque_create();

    deque_insert_first(deque, "this");
    deque_insert_last(deque, "is");
    deque_insert_last(deque, "a");
    deque_insert_index(deque, 3, "test");
    deque_insert_index(deque, 1, "code");

    DEQUE *new_deque = deque_copy(deque);

    while(deque->size != 0) {
        printf("%s\n", deque_remove_first(deque));
    }

    deque_destroy(&deque);

    if(deque == NULL) {
        printf("Deque has been destroyed.\n");
    }

    deque_insert_index(new_deque, 2, "I");
    deque_insert_last(new_deque, "said");

    deque_remove_duplicated(new_deque);

    deque_swap(new_deque, 0, 2);
    deque_swap(new_deque, 1, 6);

    deque_reverse(new_deque);
    deque_reverse(new_deque);

    DEQUE_ITERATOR it = deque_iterator_create(new_deque);
    while(it.has_next) {
        printf("%s\n", deque_read_data(&it));
    }

    deque_destroy(&new_deque);

    if(deque == NULL) {
        printf("Deque has been destroyed.\n");
    }

    return 0;
}
