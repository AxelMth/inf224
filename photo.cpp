#include <stdlib.h>
#include <cstring>
#include "photo.h"

void Photo::display(string path) const{
	string command = "open ";
	command += path;
	system(command.c_str());
}
