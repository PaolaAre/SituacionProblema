#include <iostream>
#include <string>
#include "Video.h"
#include "Video.cpp"

#ifndef EPISODE_H
#define EPISODE_H

class Episode : public Video {
public:
	Episode();
	Episode(string, int, string, string, int, string, int);
	Episode(string, int, string, string, int, string, int, int);

	void setTitle(string);
	string getTitle() const;
	void setSeason(int);
	int getSeason();
	void setNumOfEpisode(int);
	int getNumOfEpisode();

	friend ostream& operator<<(ostream& os, const Episode& ep)
	{
		os << ep.getTitle() << "\t" << ep.getDuration() << "\t" << ep.getGenre() << "\t" << ep.getRate() << endl;
		return os;
	}

private:
	string title;
	int season;
	int numOfEpisode;
};

#endif