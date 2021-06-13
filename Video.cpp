#include "Video.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void Video::setId(string b) {
	id = b;
}

string Video::getId() {
	return id;
}

void Video::setName(string a) {
	name = a;
}

string Video::getName() {
	return name;
}

void Video::setDuration(int a) {
	duration = a;
}

int Video::getDuration() const {
	return duration;
}

void Video::setGenre(string a) {
	genre = a;
}

string Video::getGenre() const {
	return genre;
}

void Video::setRate(int b) {
	rate = b;
}

int Video::getRate() const {
	return rate;
}