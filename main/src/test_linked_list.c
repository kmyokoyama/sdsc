#include <stdio.h>
#include <lists.h>

int main(int argc, char **argv) {
    LINKED_LIST *linked_list;

    linked_list = linked_list_create();

    linked_list_insert_first(linked_list, "this");
    linked_list_insert_last(linked_list, "is");
    linked_list_insert_last(linked_list, "a");
    linked_list_insert_index(linked_list, 3, "test");
    linked_list_insert_index(linked_list, 1, "code");

    LINKED_LIST *new_linked_list = linked_list_copy(linked_list);

    while(linked_list->size != 0) {
        printf("%s\n", linked_list_remove_first(linked_list));
    }

    linked_list_destroy(&linked_list);

    if(linked_list == NULL) {
        printf("Linked list has been destroyed.\n");
    }

    linked_list_insert_index(new_linked_list, 2, "I");
    linked_list_insert_last(new_linked_list, "said");

    linked_list_remove_duplicated(new_linked_list);

    linked_list_swap(new_linked_list, 0, 2);
    linked_list_swap(new_linked_list, 1, 6);

    linked_list_reverse(new_linked_list);
    linked_list_reverse(new_linked_list);

    LINKED_LIST_ITERATOR it = linked_list_iterator_create(new_linked_list);
    while(it.has_next) {
        printf("%s\n", linked_list_read_data(&it));
    }

    linked_list_destroy(&new_linked_list);

    if(linked_list == NULL) {
        printf("Linked list has been destroyed.\n");
    }

    return 0;
}
