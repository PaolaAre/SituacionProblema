#include <iostream>
#include <string>

#ifndef SERIES_H
#define SERIES_H

class Series {
public:
	string name;
	vector<Episode> episodes;

	Series();
	Series(string);
};


#endif