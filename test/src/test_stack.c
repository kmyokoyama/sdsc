#include <stdio.h>
#include <lists.h>

int main(int argc, char **argv) {
    STACK *stack;

    stack = stack_create();

    if (stack_is_empty(stack)) {
        printf("Stack is empty.\n");
    }

    stack_push(stack, "this");
    stack_push(stack, "is");
    stack_push(stack, "a");
    stack_push(stack, "test");

    if (!stack_is_empty(stack)) {
        printf("Stack is not empty.\n");
    }

    int size = stack_size(stack);
    int i;
    for(i = 0; i < size; i++) {
        printf("%s\n", stack_pop(stack));
    }

    if (stack_is_empty(stack)) {
        printf("Stack is empty.\n");
    }

    stack_destroy(&stack);
    
    return 0;
}
