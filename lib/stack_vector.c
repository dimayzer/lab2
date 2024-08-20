#include "stack_vector.h"

Stack *init_stack(int stack_size){
	Stack *stack = (Stack *)malloc(1 * sizeof(Stack));

	if(stack == NULL) {
		return NULL;
		
		} 

	stack->size = stack_size;
	stack->top = 0;
	stack->data = (char *)malloc(stack_size * sizeof(char));

	if(stack->data == NULL) {
		free(stack);
		return NULL;} // bad alloc
	return stack;
}


stack_errors push(Stack *stack, char data){
	if(stack->top == stack->size) return OVERFLOW_ERROR; //overflow	
	stack->data[stack->top] = data;
	(stack->top)++;

	return SUCCESS;
}


stack_errors pop(Stack *stack, char *data){
	if(stack == NULL) {
		return BAD_ALLOC_ERROR;
	}
	
	if(stack->top == 0) return BAD_ALLOC_ERROR; // stack is empty
	(stack->top)--;
	if(stack->data == NULL){
		return BAD_ALLOC_ERROR;
	}
	*data = stack->data[stack->top];

	
	return SUCCESS;
}


Stack* free_stack(Stack *stack){
	if(stack == NULL) return NULL;
	
	free(stack->data);
	free(stack);
	return NULL;
}

stack_errors print_stack(Stack *stack){

	if(stack == NULL) return BAD_ALLOC_ERROR;
	printf("Stack:\t");

	if(stack->top == 0) return BAD_ALLOC_ERROR; //stack is empty
	else{
		for(int i = stack->top - 1; i >= 0; i--)
			printf("%c", stack->data[i]);
		printf("\n");
	}
	return SUCCESS;
}


int is_empty(Stack *stack){
	if(stack->top == 0) return 1;
	return 0;
}

char peek(Stack *stack){
	return stack->data[stack->top];
}
