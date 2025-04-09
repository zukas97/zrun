#include "init.hpp"
#include "defs.h"
#include <cstring>

using namespace std;

Config *config;

int init(Fl_Window** win, Fl_Input** input) {
	*win = new Fl_Window(WIDTH, HEIGHT);
	//Fl_Box* box = new Fl_Box(MARGIN_X, MARGIN_Y, BOX_W, BOX_H, NULL);
	//box->box(FL_UP_BOX);
	*input = new Fl_Input(20, (HEIGHT / 2) - 30, WIDTH - 40, 30);
	//*input->value("test");
	return 0;
}

static int handler(void* user, const char* section, const char* name, const char* value) {
	if (strcmp(section, "Defaults") == 0){
		if (strcmp(name, "terminal") == 0) {
			cout << value << endl;
			strncpy(config->terminal, value, strlen(value));
			//config->terminal = (char*)value;
		}
		else if (strcmp(name, "editor") == 0) {
			//config->editor = (char*)value;
			strncpy(config->editor, value, sizeof(config->editor) - 1);
			cout << config->editor << endl;
		}
	}
	return 1;
}

Config get_config() {
	char* home = getenv("HOME");
	char filename[100];
	sprintf(filename, "%s/.config/zrun/zrun.ini", home);
	
	if (ini_parse(filename, handler, nullptr) < 0) {
		cerr << "can't load config" << endl;
	}
	//*configuration = config;
	return *config;
}
