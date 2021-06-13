#include "Episode.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

Episode::Episode() {
	setTitle("");
	setSeason(0);
	setId("0");
	setName("");
	setDuration(0);
	setGenre("");
	setNumOfEpisode(0);
	setRate(0);
}

Episode::Episode(string title, int season, string id, string name, int duration, string genre, int numOfEpisode) {
	setTitle(title);
	setSeason(season);
	setId(id);
	setName(name);
	setDuration(duration);
	setGenre(genre);
	setNumOfEpisode(numOfEpisode);
	setRate(0);
}

Episode::Episode(string title, int season, string id, string name, int duration, string genre, int numOfEpisode, int rate) {
	setTitle(title);
	setSeason(season);
	setId(id);
	setName(name);
	setDuration(duration);
	setGenre(genre);
	setNumOfEpisode(numOfEpisode);
	setRate(rate);
}

void Episode::setTitle(string a) {
	title = a;
}
string Episode::getTitle() const {
	return title;
}
void Episode::setSeason(int b) {
	season = b;
}
int Episode::getSeason() {
	return season;
}
void Episode::setNumOfEpisode(int b) {
	numOfEpisode = b;
}
int Episode::getNumOfEpisode() {
	return numOfEpisode;
}