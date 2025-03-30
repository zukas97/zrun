#include "backend.hpp"
#include <unistd.h>

char** parse_words(const char* str, int* len) {
	char* tok = strtok((char*)str, " ");
	char** words;
	int i = 0;
	while (tok != NULL) {
		words[i] = tok;
		tok = strtok(NULL, " ");
		i++;
	}
	*len = i;
	//cout << words[0] << endl;
	return words;
}

void execute(char** argv, int words) {
	//char command[100];
	//sprintf(command, "/usr/bin/%s", argv[1]);

	char* args[words];
	if (words > 2) {
		for (int i=0; i < (words - 1); i++) {
			args[i] = argv[i+1];
			//std::cout << args[i] << std::endl;
		}
		args[words] = NULL;
		
		execvp(argv[1], args);
	}
	else {
		execvp(argv[1], NULL);
	}

}

int run_commands(char** argv, int words) {
	std::string s[words];
	for (int i=0; i < words; i++) {
		s[i].assign(argv[i]);
	}

	// execute
	if (s[0] == "x") {
		execute(argv, words);

		return 0;
	} 
	// edit file
	else if (s[0] == "e") {
		char* ed_args[3];
		char* editor = getenv("EDITOR");
		std::cout << editor << std::endl;
		ed_args[0] = editor;
		ed_args[1] = (char*)s[1].c_str();
		ed_args[2] = NULL;
		execvp(editor, ed_args);

	}

	// cmd not found
	else {
		return 1;
	}
	return 0;
}
