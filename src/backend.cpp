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
	char* args[words];
	for (int i=0; i < (words - 1); i++) {
		args[i] = argv[i+1];
		std::cout << args[i] << std::endl;
	}
	args[words] = NULL;
	
	if (execvp(argv[1], args) < 0) {
		std::cout << "zrun: x: command not found:  " << argv[1] << std::endl;
	}

}

int run_commands(char** argv, int words, Config config) {
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
		char* ed_args[4];
		char* editor = config.editor;
		std::cout << config.editor << std::endl;
		//if (config.editor[0] =='\0') {
		//	editor = getenv("EDITOR");
		//}
		if (editor == NULL) {
			printf("EDITOR not set. Defaulting to vim");
			strncpy(editor, "vim", 4);
		}
		if (config.editor_terminal) {
			ed_args[0] = config.terminal;
			ed_args[1] = editor;
			ed_args[2] = argv[1];
			ed_args[3] = NULL;

		} else {
			ed_args[0] = editor;
			ed_args[1] = (char*)s[1].c_str();
			ed_args[2] = NULL;
			ed_args[3] = NULL;
		}
		execvp(ed_args[0], ed_args);

	}

	// cmd not found
	else {
		return 1;
	}
	return 0;
}
