#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct Config {
	char* editor;
	char* terminal;
	bool editor_terminal;
};

char** parse_words(const char* str, int* len);

int run_commands(char** argv, int words, Config config);

void execute(char** argv, int words);


