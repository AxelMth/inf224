#include <stdlib.h>
#include <cstring>
#include "photo.h"

using namespace std;

void Photo::display(string path) const{
	string command = "imagej ";
	command += path;
	system(command.c_str());
}
