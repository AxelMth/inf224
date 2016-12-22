#include <stdlib.h>
#include <cstring>
#include "video.h"

Video::Video (string _name, string _path, int _total_length){
	name = _name;
	path = _path;
	total_length = _total_length;
}

void Video::display() const{
	string command = "open ";
	command += path;
	system(command.c_str());
}
