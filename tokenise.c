#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

const int MAX_STRING = 256;

int tokenise(char str[], int start, char result[]);

int main() {
	char buffer[MAX_STRING];
	printf("Enter a sentence up to length 255\n");

	// Checks for an error input
	assert(fgets(buffer, MAX_STRING, stdin) != NULL);
	printf("%s\n", buffer);

	char result[MAX_STRING];
	int wordNumber = 1;
	int start = 0;
	while(start != -1) {
		start = tokenise(buffer, start, result);
		int letterIndex = 0;
		printf("Word %d: ", wordNumber);
		/* Looks for a null string terminator to finish
		   printing out the last string in result
		*/ 
		while(result[letterIndex] != 0) {
			printf("%c", result[letterIndex]);
			letterIndex++;
		}
		printf("\n");
		wordNumber++;
	}

	return 0;
}

int tokenise(char str[], int start, char result[]) {
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
