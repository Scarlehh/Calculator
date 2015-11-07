#ifndef STACK_H
#define STACK_H

const int MAX_STACK;

typedef struct {
	double* my_stack;
	int pointer;
} Stack;

Stack* new_stack();
void delete_stack(Stack* this);
void push(Stack* this, double val);
double pop(Stack* this);
double peek(Stack* this);
void add(Stack* this);
void subtract(Stack* this);
void multiply(Stack* this);
void divide(Stack* this);

#endif
