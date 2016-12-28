#include <stdlib.h>
#include <cstring>
#include "photo.h"

void Photo::display() {
	string command = "imagej ";	
	command += path;
	system(command.c_str());
}

void Photo::affiche() {
	cout << "Les attributs de la photo sont : " << endl;
	cout << "nom: " << name << endl;
	cout << "chemin: " << path << endl;
	cout << "latitude: " << latitude << endl;
	cout << "longitude: " << longitude << endl;
}
