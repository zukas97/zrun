#include "init.hpp"
#include "defs.h"

int init(Fl_Window** win, Fl_Input** input) {
	*win = new Fl_Window(WIDTH, HEIGHT);
	//Fl_Box* box = new Fl_Box(MARGIN_X, MARGIN_Y, BOX_W, BOX_H, NULL);
	//box->box(FL_UP_BOX);
	*input = new Fl_Input(20, (HEIGHT / 2) - 30, WIDTH - 40, 30);
	//*input->value("test");
	return 0;
}
