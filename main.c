#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>




#if (STACK_TYPE == VECTOR)
	#include "lib/stack_vector.h"
#else
	#include "lib/stack_list.h"
#endif


int is_operator(char symbol){
	return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int priority(char symbol){
	switch(symbol){
		case '+':
			return 1;
		case '-': 
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		default:
			return 0;
	}
}



int main(){
	int size;
	printf("Введите длину стэка: ");
	if(scanf("%d", &size) == 1 ){
	Stack *stack = init_stack(size);


	char *symbol = NULL; 
	symbol =(char *)calloc(1, sizeof(char));
	
	char *infix;
	infix = readline("Введите выражение в инфиксном виде: ");
	if(infix != NULL){
	

	char *postfix = NULL;

	postfix = (char *)calloc((strlen(infix)+1), sizeof(char));
	unsigned long j = 0;
	for(unsigned long i = 0 ; i < strlen(infix); i++){
		if(!is_operator(infix[i]) && infix[i] != '(' && infix[i] != ')'){
			postfix[j++] = infix[i];

		}

		else{
			if(is_operator(infix[i])){
				if(is_empty(stack) || peek(stack) == '('){
					push(stack, infix[i]);
					}
				else{
					if(priority(infix[i]) > priority(peek(stack))){
						push(stack, infix[i]);
					}			
					else{
						while(!is_empty(stack) && (peek(stack) != '(' || priority(peek(stack)) >= priority(infix[i]))){
							pop(stack, symbol);
							postfix[j++] = *symbol;
							}
						push(stack, infix[i]);
						
					}
				}
			}
			
			if(infix[i] == '('){
				push(stack, infix[i]);
			}
			if(infix[i] == ')'){
					while(peek(stack) != '('){
						pop(stack, symbol);
						postfix[j++] = *symbol;
				
						}
					
				pop(stack, symbol);
							
			}
			
		}
	

	}
	while( !is_empty(stack) && stack != NULL && stack->top != 0){
		pop(stack, symbol);
		postfix[j++] = *symbol;		
	}
	
		
		
		printf("Постфиксная форма записи: ");
		for(unsigned long k= 0; k < j; k++) {
			printf("%c", postfix[k]);}

		free(postfix);
		}
		free(symbol);
		free_stack(stack);
		free(infix);
		}
		
		return 0;
	}
	
	
