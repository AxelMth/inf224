#include <stdlib.h>
#include <cstring>
#include "video.h"

using namespace std;

void Video::display(string path) const{
	string command = "mpv ";
	command += path;
	system(command.c_str());
}
