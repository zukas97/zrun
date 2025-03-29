#include <cstring>
#include <iostream>
#include <string>
#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include "init.hpp"
#include "parse.hpp"
#include "defs.h"

using namespace std;

void Input_Callback(Fl_Widget* widget, void* data) {
	Fl_Window* win = (Fl_Window*)data;
	Fl_Input* input = (Fl_Input*)widget;
	cout << "enter\n";

	// Parse command
	char** words = parse_words(input->value());
	cout << words[0] << endl;
	
	// Close window
	win->hide();
	delete win;
}

int main(int argc, char** argv) {
	Fl_Window* win;
	Fl_Input* input;
	init(&win, &input);
	win->set_non_modal();
	input->when(FL_WHEN_ENTER_KEY);
	input->callback(Input_Callback, win);
	
	win->end();
	win->show(argc, argv);
	return Fl::run();
}

