//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "tcpserver.h"
#include "photo.h"
#include "table.h"
#include "video.h"

using namespace std;
using namespace cppu;

const int PORT = 3331;

class MyBase : public Table{
public:

  bool processRequest(TCPConnection& cnx, const string& request, string& response)
  {
  cerr << "\nRequest: '" << request << "'" << endl;

	stringstream ss(request);
	stringstream rep;

	// On sépare le requêtes
	string command;
	string type;
	string name;
	string path;

	// Attribut photo
	string longitude;
	string latitude;

	// Attribut video
	string total_length;

	// Attributs film
	string number_chapter;
	int tableau[20];

	ss >> command;

	if (command == "create" || command == "delete"){
		TCPLock lock(cnx, true);
	}
	else TCPLock lock(cnx);

	if (command == "close")
		return false;

	if (command == "create")
		ss >> type >> name >> path;

	if (command == "read")
		ss >> name;

	if (command  == "display")
		displayAll(rep);

	if (command == "delete"){
		ss >> name;
		deleteByName(name,rep);
	}

	if(type == "photo"){
		ss >> longitude >> latitude;
	}

	else if (type == "video"){
		ss >> total_length;
	}

	else if (type == "film"){
		ss >> total_length >> number_chapter;
		int i = 0;
		while (!ss.eof() && i < 20){
			string current;
			ss >> current;
			*(tableau+i) = stoi(current);
			i++;
		}

	}

	if(command == "create"){
		if(type == "photo"){
			createPhoto(name,path,stof(longitude),stof(latitude));
			rep << "Photo bien créée ! " << endl;
		}
		else if (type == "video"){
			createVideo(name,path,stoi(total_length));
			rep << "Vidéo bien créée ! " << endl;
		}
		else if (type == "film"){
			createFilm(name,path,stoi(total_length),stoi(number_chapter),tableau);
			rep << "Film bien créé ! " << endl;
		}
		else if (type == "groupe"){
			createGroupe(name);
			rep << "Groupe bien créé ! " << endl;
		}
	}
	else if (command == "read"){
		play(name,rep);
	}

    response = rep.str();

    replace(response.begin(),response.end(),'\n',';');

    cerr << "Response: " << response << endl;

    // renvoyer false si on veut clore la connexion avec le client
    return true;
  }
};


int main(int argc, char* argv[])
{
  // cree le TCPServer
  shared_ptr<TCPServer> server(new TCPServer());

  // cree l'objet qui gère les données
  shared_ptr<MyBase> base(new MyBase());

  // le serveur appelera cette méthode chaque fois qu'il y a une requête
  server->setCallback(*base, &MyBase::processRequest);

  // lance la boucle infinie du serveur
  cout << "Starting Server on port " << PORT << endl;
  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
  }

  return 0;
}
