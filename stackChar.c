#include "stackChar.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static const int MAX_STACK = 1024;

StackChar* new_char_stack() {
	StackChar* stack = malloc(sizeof(StackChar));
	stack->my_stack = malloc(MAX_STACK*sizeof(char));
	stack->pointer=0;
	
	return stack;
}

void delete_char_stack(StackChar* this) {
	free(this->my_stack);
	free(this);
}

void push_char(StackChar* this, char character) {
	this->my_stack[this->pointer] = character;
	this->pointer++;
}

char pop_char(StackChar* this) {
	this->pointer--;
	return this->my_stack[this->pointer];
}

char peek_char(StackChar* this) {
	if(!isEmpty(this)) {
		return this->my_stack[(this->pointer)-1];
	}
	return 0;
}

// Returns true if higher precendence is on the stack
bool check_precedence(StackChar* this, char operator) {
	switch(operator) {
		case '-':
		case '+':
			if(peek_char(this) == '*' || peek_char(this) == '*') {
				return true;
			}
			break;
	}
	return false;
}

bool isEmpty(StackChar* this) {
	if(this->pointer == 0) {
		return true;
	}
	return false;
}
