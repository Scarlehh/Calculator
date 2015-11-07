#ifndef STACKCHAR_H
#define STACKCHAR_H

#include <stdbool.h>

typedef struct {
	char* my_stack;
	int pointer;
} StackChar;

StackChar* new_char_stack();
void delete_char_stack(StackChar* this);
void push_char(StackChar* this, char character);
char pop_char(StackChar* this);
char peek_char(StackChar* this);
bool check_precedence(StackChar* this, char operator);
bool isEmpty(StackChar* this);

#endif
