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
    unsigned int size;
} STACK;

STACK *stack_create(); 
unsigned int stack_push(STACK *stack, const STACK_DATA data);
STACK_DATA stack_pop(STACK *stack);
int stack_size(const STACK *stack);
int stack_is_empty(const STACK *stack);
void stack_destroy(STACK **ref_stack);

#endif //_STACK_H_
