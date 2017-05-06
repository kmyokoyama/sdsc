#ifndef _STACK_H_
#define _STACK_H_

#include <common.h>

typedef _DATA STACK_DATA;

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

struct stack_api {
    STACK *(*create_stack)(); 
    unsigned int (*push)(STACK *, const STACK_DATA);
    STACK_DATA (*pop)(STACK *);
    int (*size)(const STACK *);
    int (*is_empty)(const STACK *);
    void (*destroy)(STACK **);
};

typedef struct stack_api STACK_API;

STACK_API *new_stack_api();

#endif //_STACK_H_
