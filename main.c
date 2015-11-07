#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <errno.h>
#include "tokenise.h"

int getNum(char buffer[], int* index);

int main() {
	Stack *stack = new_stack();

	printf("Enter sting: ");
	char buffer[MAX_STACK];
	fgets(buffer, MAX_STACK, stdin);
	char result[MAX_STACK];
	int start = 0;

	while(start != -1) {
		start = tokenise(buffer, start, result);
		char operator;
		double val;
		sscanf(result, "%c", &operator);
		switch(operator) {
			case '+':
				add(stack);
				break;
			case '-':
				subtract(stack);
				break;
			case '*':
				multiply(stack);
				break;
			case '/':
				divide(stack);
				break;
			default:
				sscanf(result, "%lf", &val);
				push(stack, val);
		}
	}
	printf("End result is: %lf\n", peek(stack));

	delete_stack(stack);
	return 0;
}

