#include "backend.hpp"
#include <unistd.h>

char** parse_words(const char* str, int* len) {
	char* tok = strtok((char*)str, " ");
	//char* rest = (char*)str;
	char** words;
	int i = 0;
	while (tok != NULL) {
		words[i] = tok;
		//std::cout << tok << std::endl;
		tok = strtok(NULL, " ");
		i++;
	}
	*len = i;
	return words;
}

int run_commands(char** argv, int words) {
	//std::cout << argv[1] << std::endl;	
	std::string s[words];
	for (int i=0; i < words; i++) {
		s[i].assign(argv[i]);
	}
	//std::cout << s[0] << std::endl;

	if (s[0] == "x") {
		//std::cout << s[1] << std::endl;
		//system(s[1].c_str());
		char command[100];
		sprintf(command, "/usr/bin/%s", s[1].c_str());
		execvp(command, NULL);
		return 0;
	} else {
		return 1;
	}

}
