#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct Config {
	char editor[64];
	char terminal[64];
};

char** parse_words(const char* str, int* len);

int run_commands(char** argv, int words, Config config);

void execute(char** argv, int words);


