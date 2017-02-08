#include <stdlib.h>
#include <cstring>
#include "photo.h"

void Photo::play() {
	string command = "imagej ";
	command += path;
	system(command.c_str());
}

void Photo::affiche(ostream& s) {
	s << "Les attributs de la photo sont : " << endl;
	s << "nom: " << name << endl;
	s << "chemin: " << path << endl;
	s << "latitude: " << latitude << endl;
	s << "longitude: " << longitude << endl;
}
