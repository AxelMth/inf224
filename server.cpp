//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "photo.h"

using namespace std;
using namespace cppu;

const int PORT = 3331;

class MyBase {
public:
  Table *t;
  /* Cette méthode est appelée chaque fois qu'il y a une requête à traiter.
   * Ca doit etre une methode de la classe qui gere les données, afin qu'elle
   * puisse y accéder.
   *
   * Arguments:
   * - 'request' contient la requête
   * - 'response' sert à indiquer la réponse qui sera renvoyée au client
   * - si la fonction renvoie false la connexion est close.
   *
   * Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
   * un thread par client).
   *
   * Pour eviter les problemes de concurrence on peut créer un verrou en creant
   * une variable Lock **dans la pile** qui doit etre en mode WRITE (2e argument = true)
   * si la fonction modifie les donnees.
   */
  bool processRequest(TCPConnection& cnx, const string& request, string& response)
  {
	cerr << "Merci de renseigner le type de reque sous la forme :" << endl;
	cerr << "Commande Type Nom Chemin <Attributs" << endl;

    	cerr << "\nRequest: '" << request << "'" << endl;	

	stringstream ss;

	ss << request;
	
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
	
	ss >> command >> type >> name >> path;

	switch(type){
		case "photo":
			ss >> longitude >> latitude;
			break;
		case "video":
			ss >> total_length;
			break;
	}

	switch(command){	
		case "create":
			switch(type){
				case "photo":
					t->createPhoto(name,path,longitude,latitude);
					break;
				case "video":
					t->createVideo(name,path,total_length);
					break;
			}
			break;
		case "read":
			t->display(
	}	
	Photo * p = new Photo("Photo",path,0,0);
	
	if (command == "display")
		p->display();

    // 1) pour decouper la requête:
    // on peut par exemple utiliser stringstream et getline()
    
    
    // 2) faire le traitement:
    // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
    // - sinon juste: TCPLock lock(cnx);


    // 3) retourner la reponse au client:
    // - pour l'instant ca retourne juste OK suivi de la requête
    // - pour retourner quelque chose de plus utile on peut appeler la methode print()
    //   des objets ou des groupes en lui passant en argument un stringstream
    // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
    //   ils servent à délimiter les messages entre le serveur et le client
    
    response = "OK: " + command + ' ' + path;
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

