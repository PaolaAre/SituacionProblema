#include "Movie.h"
//#include "Video.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

Movie::Movie() {
	setTitle("");
	setId("0");
	setName("");
	setDuration(0);
	setGenre("");
	setRate(0);
}

Movie::Movie(string title, string id, string name, int duration, string genre) {
	setTitle(title);
	setId(id);
	setName(name);
	setDuration(duration);
	setGenre(genre);
	setRate(0);
}

Movie::Movie(string title, string id, string name, int duration, string genre, int rate) {
	setTitle(title);
	setId(id);
	setName(name);
	setDuration(duration);
	setGenre(genre);
	setRate(rate);
}

void Movie::setTitle(string a) {
	title = a;
}
string Movie::getTitle() const {
	return title;
}