#include "Series.h"
#include "Episode.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

Series::Series() {
	name = "";
}
Series::Series(string a) {
	name = a;
}