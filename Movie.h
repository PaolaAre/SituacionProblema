#include <iostream>
#include <string>
#include "Video.h"

#ifndef MOVIE_H
#define MOVIE_H

class Movie : public Video {
public:
	Movie();
	Movie(string, string, string, int, string);
	Movie(string, string, string, int, string, int);
	void setTitle(string);
	string getTitle() const;

	friend ostream& operator<<(ostream& os, const Movie& mov)
	{
		os << mov.getTitle() << "\t" << mov.getDuration() << "\t" << mov.getGenre() << "\t" << mov.getRate() << endl;
		return os;
	}
private:
	string title;
};

#endif