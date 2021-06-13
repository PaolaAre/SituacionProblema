#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Video.h"
#include "Movie.h"
#include "Series.h"
#include "Episode.h"
using namespace std;

vector<string> split(string str, char pattern) {

	int posInit = 0;
	int posFound = 0;
	string splitted;
	vector<string> results;

	while (posFound >= 0) {
		posFound = str.find(pattern, posInit);
		splitted = str.substr(posInit, posFound - posInit);
		posInit = posFound + 1;
		results.push_back(splitted);
	}

	return results;
}

class Manager {
public:
	int option;
	vector<Video> dbVideos;
	vector<Movie> dbMovies;
	vector<Series> dbSeries;
	void option1();
	void option2();
	void option3();
	void option4();
	void option5();
};

