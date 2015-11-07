#include <stdio.h>
#include <stdlib.h>
#include "tokenise.h"

int tokenise(char str[], int start, char result[]) {
	// Ensures no trailing spaces
	while(str[start] == ' ') {
		start++;
	}
	int i;
	for(i = 0; str[start] != ' ' && str[start] != 0; i++, start++) {
		result[i] = str[start];
	}
	result[i] = 0;	
	if(str[start] == 0) {
		return -1;
	}
	return start;
}
