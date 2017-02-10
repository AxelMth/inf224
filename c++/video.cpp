#include <stdlib.h>
#include <cstring>
#include "video.h"

void Video::play() {
	string command = "mpv ";
	command += path;
	system(command.c_str());
}

void Video::affiche(ostream& s){
	s << "Les attributs de la vidéo sont : " << endl;
	s << "nom: " << name << endl;
	s << "chemin: " << path << endl;
	s << "durée: " << total_length << endl;
}

void Video::write(ostream& f){
	f << "Video" << "\n" << name << "\n" << path << "\n";
	f << total_length << "\n";
	f.flush();
}

void Video::read(istream& f){
	string name;
	string path;
	string total_length;
	getline(f,name);
	getline(f,path);
	getline(f,total_length);
	this->name = name;
	this->path = path;
	this->total_length = stoi(total_length);
}
