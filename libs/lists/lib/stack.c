#include <stdlib.h>
#include <stack.h>

STACK *stack_create() {
    STACK *stack;

    stack = (STACK *) malloc(sizeof(STACK));

    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;

    return(stack);
}

void stack_push(STACK *stack, STACK_DATA data) {
    STACK_NODE *new_node;

    new_node = (STACK_NODE *) malloc(sizeof(STACK_NODE));

    new_node->data = data;

    if(stack->size == 0) {
        new_node->next = stack->head;
        stack->head = new_node;
    }
    else {
        new_node->next = stack->tail;
    }

    stack->tail = new_node;

    stack->size++;
}

STACK_DATA stack_pop(STACK *stack) {
    if(stack->size == 0) {
        return NULL;
    }

    STACK_NODE *last = stack->tail;
    STACK_DATA data = last->data;

    stack->tail = last->next;

    if(stack->tail == NULL) {
        stack->head = NULL;
    }

    free(last);
    stack->size--;

    return(data);
}

int stack_size(STACK *stack) {
    return stack->size;
}

int stack_is_empty(STACK *stack) {
    return (stack->size == 0 ? 1 : 0);
}

void stack_destroy(STACK **ref_stack) {
    if((*ref_stack)->size == 0) {
        free(*ref_stack);
        *ref_stack = NULL;

        return;
    }

    STACK_NODE *current;
    current = (*ref_stack)->tail;

    while(current != NULL) {
        STACK_NODE *tmp = current->next;
        free(current);
        current = tmp;
    }

    free(*ref_stack);
    *ref_stack = NULL;
}
