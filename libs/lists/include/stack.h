#ifndef _STACK_H_
#define _STACK_H_

typedef char* STACK_DATA;

typedef struct stack_node {
    STACK_DATA data;
    struct stack_node *next;
} STACK_NODE;

typedef struct stack {
    STACK_NODE *head;
    STACK_NODE *tail;
    int size;
} STACK;

typedef struct iterator_stack {
    STACK_NODE *node;
    int position;
    int has_next;
} STACK_ITERATOR;

STACK *stack_create(); 
void stack_push(STACK *stack, STACK_DATA data);
STACK_DATA stack_pop(STACK *stack);
int stack_size(STACK *stack);
int stack_is_empty(STACK *stack);
void stack_destroy(STACK **ref_stack);

#endif //_STACK_H_
