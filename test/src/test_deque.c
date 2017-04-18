#include <stdio.h>
#include <lists.h>

int main(int argc, char **argv) {
    DEQUE *deque;

    deque = deque_create();

    if (deque != NULL) {
        printf("Deque has been created successfully.\n");
    }

    deque_insert_first(deque, "is");
    deque_insert_first(deque, "This");
    deque_insert_last(deque, "code");
    deque_insert_last(deque, "test");
    deque_insert_last(deque, "a");

    printf("%s\n", deque_remove_first(deque));
    printf("%s\n", deque_remove_first(deque));
    printf("%s\n", deque_remove_last(deque));
    printf("%s\n", deque_remove_last(deque));
    printf("%s\n", deque_remove_last(deque));

    while(deque->size != 0) {
        printf("%s\n", deque_remove_first(deque));
    }

    deque_destroy(&deque);

    if(deque == NULL) {
        printf("Deque has been destroyed.\n");
    }

    return 0;
}
