#include <stdlib.h>
#include <cstring>
#include "video.h"

using namespace std;

Video::Video (string _name, string _path, int _total_length){
	name = _name;
	path = _path;
	total_length = _total_length;
}

void Video::display(string path) const{
	string command = "mpv ";
	command += path;
	system(command.c_str());
}
