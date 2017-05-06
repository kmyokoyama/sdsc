#include <stdio.h>
#include <sdsc.h>

int main(int argc, char **argv) {
    STACK *stack;
    STACK_API *api;

    api = new_stack_api();

    stack = api->create_stack();

    if (api->is_empty(stack)) {
        printf("Stack is empty.\n");
    }

    api->push(stack, "this");
    api->push(stack, "is");
    api->push(stack, "a");
    api->push(stack, "test");

    if (api->is_empty(stack)) {
        printf("Stack is empty.\n");
    }
    else {
        printf("Stack is not empty.\n");
    }

    int size = api->size(stack);
    int i;
    for(i = 0; i < size; i++) {
        printf("%s\n", as_str(api->pop(stack)));
    }

    if (api->is_empty(stack)) {
        printf("Stack is empty.\n");
    }
    else {
        printf("Stack is not empty.\n");
    }

    api->destroy(&stack);

    return 0;
}
