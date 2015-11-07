#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <errno.h>
#include "tokenise.h"
#include "stackChar.h"
#include <stdbool.h>

void RPNimplementation(Stack stack[], char buffer[]);

int main() {
	printf("Enter sting: ");
	char buffer[MAX_STACK];
	fgets(buffer, MAX_STACK, stdin);

	char rpnBuffer[MAX_STACK];
	int rpnIndex = 0;

	StackChar *charStack = new_char_stack();
	char result[MAX_STACK];
	int start = 0;
	while(start != -1) {
		start = tokenise(buffer, start, result);
		char operator;
		sscanf(result, "%c", &operator);
		// If token is a number, append to buffer
		if(operator >= '0' && operator <= '9') {
			int index = 0;
			while(result[index] != 0 && result[index] != '\n') {
				rpnBuffer[rpnIndex] = result[index];
				rpnIndex++;
				index++;
			}
			// Fix newline input
			rpnBuffer[rpnIndex] = ' ';
			rpnIndex++;
		}
		else if(operator == '(') {
			push_char(charStack, operator);
		}
		else if(operator == '+' || operator == '-' || operator == '*' || operator == '/') {
		// Changes begin
			if(operator == '-' && result[1] >= '0' && result[1] <= '9') {
				int index = 0;
				while(result[index] != 0 && result[index] != '\n') {
					rpnBuffer[rpnIndex] = result[index];
					rpnIndex++;
					index++;
				}
				rpnBuffer[rpnIndex] = ' ';
				rpnIndex++;
			}
		// Changes end
			else {
				if(check_precedence(charStack, operator)) {
					// pop everything off the stack
					while(!isEmpty(charStack)) {
						rpnBuffer[rpnIndex] = pop_char(charStack);
						rpnIndex++;
						rpnBuffer[rpnIndex] = ' ';
						rpnIndex++;
					}
				}
				push_char(charStack, operator);
			}
		}
		else if(operator == ')') {
			while(peek_char(charStack) != '('){
				rpnBuffer[rpnIndex] = pop_char(charStack);
				rpnIndex++;
				rpnBuffer[rpnIndex] = ' ';
				rpnIndex++;
			}
			pop_char(charStack);
		}
	}
	// Pop remaining items
	while(!isEmpty(charStack)) {
		rpnBuffer[rpnIndex] = pop_char(charStack);
		rpnIndex++;
		rpnBuffer[rpnIndex] = ' ';
		rpnIndex++;
	}
	rpnBuffer[rpnIndex] = 0;

	delete_char_stack(charStack);

	printf("%s\n", rpnBuffer);

	Stack *rpnStack = new_stack();
	RPNimplementation(rpnStack, rpnBuffer);
	printf("The end result is: %lf\n", peek(rpnStack));
	delete_stack(rpnStack);

	return 0;
}
	
void RPNimplementation(Stack stack[], char buffer[]) {
	char result[MAX_STACK];
	int start = 0;
	while(start != -1) {
		start = tokenise(buffer, start, result);
		char operator;
		double val;
		sscanf(result, "%c", &operator);
		if(operator == '-' && result[1] >= '0' && result[1] <= '9') {
			sscanf(result, "%lf", &val);
			push(stack, val);
		} else {
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
	}
}
