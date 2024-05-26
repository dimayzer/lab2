#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef enum stack_errors {
	SUCCESS,
	BAD_ALLOC_ERROR,
	OVERFLOW_ERROR
} stack_errors;

typedef struct Node{
	char data;
	struct Node *next;
} Node;

typedef struct Stack{
	Node *top;
} Stack;



stack_errors push(Stack *stack, char data);
stack_errors pop(Stack *stack, char *data);
Node *add_node(char data);
Stack *init_stack(void);
Stack * free_stack(Stack *stack);
stack_errors print_stack(Stack *stack);

#endif /* STACK_LIST_H */
