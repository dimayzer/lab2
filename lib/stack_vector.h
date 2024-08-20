#ifndef STACK_VECTOR_H
#define STACK_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef enum stack_errors {
	SUCCESS,
	BAD_ALLOC_ERROR,
	OVERFLOW_ERROR
} stack_errors;

typedef struct Stack{
	int size;
	int top;
	char *data;
} Stack;

stack_errors push(Stack *stack, char data);
stack_errors pop(Stack *stack, char *data);
Stack *init_stack(int stack_size);
Stack* free_stack(Stack *stack);
stack_errors print_stack(Stack *stack);
int is_empty(Stack *stack);
char peek(Stack *stack);

#endif /* STACK_VECTOR_H */
