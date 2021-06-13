#include <iostream>
#include <string>

#ifndef VIDEO_H
#define VIDEO_H

class Video {
public:
	void setId(string);
	string getId();
	void setName(string);
	string getName();
	void setDuration(int);
	int getDuration() const;
	void setGenre(string);
	string getGenre() const;
	void setRate(int);
	int getRate() const;

	friend ostream& operator<<(ostream& os, const Video& video)
	{
		os << video.name << "\t" << video.duration << "\t" << video.genre << "\t" << video.rate << endl;
		return os;
	}

private:
	string id;
	string name;
	int duration;
	string genre;
	int rate;
};

#endif