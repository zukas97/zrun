#include <cstring>
#include <iostream>
#include <string>
#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include "init.hpp"
#include "defs.h"

using namespace std;

Config configuration;

void Input_Callback(Fl_Widget* widget, void* data) {
	Fl_Window* win = (Fl_Window*)data;
	Fl_Input* input = (Fl_Input*)widget;

	// Parse command
	int word_count;
	char** words = parse_words(input->value(), &word_count);
	if (run_commands(words, word_count, configuration) != 0) {
		cout << "command not found" << endl;
	} 
	
	// Close window
	win->hide();
	delete win;
}

int main(int argc, char** argv) {
	Fl_Window* win;
	Fl_Input* input;
	init(&win, &input);
	//get_config(&configuration);
	configuration = get_config();
	cout << configuration.editor << endl;
	win->set_non_modal();
	input->when(FL_WHEN_ENTER_KEY);
	input->callback(Input_Callback, win);
	
	win->end();
	win->show(argc, argv);
	return Fl::run();
}

