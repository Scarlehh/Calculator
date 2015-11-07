#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

const int MAX_STACK = 1024;

Stack* new_stack() {
	Stack* stack = malloc(sizeof(Stack));
	stack->my_stack = malloc(MAX_STACK*sizeof(double));
	stack->pointer=0;

	return stack;
}

void delete_stack(Stack* this) {
	free(this->my_stack);
	free(this);
}

void push(Stack* this, double val) {
	this->my_stack[this->pointer] = val;
	this->pointer++;
}

double pop(Stack* this) {
	this->pointer--;
	return this->my_stack[this->pointer];
}

double peek(Stack* this) {
	return this->my_stack[(this->pointer)-1];
}

void add(Stack* this) {
	double val2 = pop(this);
	double val1 = pop(this);
	push(this, val1+val2);
	printf("Result of addition: %lf\n", peek(this));
}

void subtract(Stack* this) {
	double val2 = pop(this);
	double val1 = pop(this);
	push(this, val1-val2);
	printf("Result of subtraction: %lf\n", peek(this));
}

void multiply(Stack* this) {
	double val2 = pop(this);
	double val1 = pop(this);
	push(this, val1*val2);
	printf("Result of multiplication: %lf\n", peek(this));
}

void divide(Stack* this) {
	double val2 = pop(this);
	double val1 = pop(this);
	push(this, val1/val2);
	printf("Result of division: %lf\n", peek(this));
}
