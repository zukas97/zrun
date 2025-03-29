#include "parse.hpp"

char** parse_words(const char* str) {
	char** words;
	char* tok = strtok((char*)str, " ");
	//char* rest = (char*)str;
	int i = 0;
	while (tok != NULL) {
		words[i] = tok;
		tok = strtok(NULL, " ");
		i++;
	}
	return words;
}
