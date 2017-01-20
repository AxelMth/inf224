#include <stdlib.h>
#include <cstring>
#include "video.h"

Video::Video (string _name, string _path, int _total_length){
	name = _name;
	path = _path;
	total_length = _total_length;
}

void Video::play() {
	string command = "mpv ";
	command += path;
	system(command.c_str());
}

void Video::affiche(){
	cout << "Les attributs de la vidéo sont : " << endl;
	cout << "nom: " << name << endl;
	cout << "chemin: " << path << endl;
	cout << "durée: " << total_length << endl;
}
