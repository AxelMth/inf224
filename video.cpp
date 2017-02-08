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
