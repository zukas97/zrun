#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


char** parse_words(const char* str, int* len);

int run_commands(char** argv, int words);
