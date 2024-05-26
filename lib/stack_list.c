#include "stack_list.h"



Stack *init_stack(void){
	Stack *stack = (Stack *)calloc(1, sizeof(Stack));

	if(stack == NULL) return NULL;
	return stack;
}


Node *add_node(char data){
	Node *node = (Node *)calloc(1, sizeof(Node));

	if(node == NULL) return NULL; 

	node->next = NULL;
	node->data = data;

	return node;
}


stack_errors push(Stack *stack, char data){
	Node *node = add_node(data);
	
	if(node == NULL || stack == NULL) return BAD_ALLOC_ERROR; 

	node->next = stack->top;
	stack->top = node;
	return SUCCESS;
}


stack_errors pop(Stack *stack, char *data){

	if(stack == NULL || stack->top == NULL) return BAD_ALLOC_ERROR; // stack is empty
	Node *node = stack->top;
	*data = stack->top->data;
	stack->top = stack->top->next;
	free(node);
	return SUCCESS; //success
		
}


Stack *free_stack(Stack *stack){

	if(stack == NULL) return NULL;
	
	Node *node = stack->top;
	Node *tmp = node;

	while(node != NULL){
		tmp = node->next;

		free(node);
		node = tmp;
	}
	free(node);
	free(stack);
	return NULL;
}



stack_errors print_stack(Stack *stack){
	if(stack == NULL || stack->top == NULL) return BAD_ALLOC_ERROR;
	printf("Stack:\t");
	Node *node = stack->top;
	while(node != NULL){
		printf("%c", node->data);
		node = node->next;
	}	

	printf("\n");
	return SUCCESS;
}
