#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include "init.hpp"


int main(int argc, char** argv) {
	Fl_Window* win;
	Fl_Input* input;
	init(&win, &input);
	
	win->end();
	win->show(argc, argv);
	return Fl::run();
}
