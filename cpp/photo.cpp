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

void Photo::write(ostream& f){
	f << "Photo" << "\n" << name << "\n" << path << "\n";
	f << longitude << "\n" << latitude << "\n";
	f.flush();
}

void Photo::read(istream& f){
	string name;
	string path;
	string longitude;
	string latitude;
	getline(f,name);
	getline(f,path);
	getline(f,longitude);
	getline(f,latitude);
	this->name = name;
	this->path = path;
	this->longitude = stof(longitude);
	this->latitude = stof(latitude);
}
