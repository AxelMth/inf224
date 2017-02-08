#include "table.h"

Pptr Table::createPhoto(string name, string path, double longitude, double latitude){
  shared_ptr<Photo> p(new Photo(name,path,longitude,latitude));
  obj_table[name] = p;
  return p;
}

Vptr Table::createVideo(string name, string path, int length){
  shared_ptr<Video> v(new Video(name,path,length));
  obj_table[name] = v;
  return v;
}

Fptr Table::createFilm(string name, string path, int length, int number_chapter, int * tab){
  shared_ptr<Film> f(new Film(name,path,length,number_chapter,tab));
  obj_table[name] = f;
  return f;
}

Gptr Table::createGroupe(string name){
  shared_ptr<Groupe> g(new Groupe(name));
  grp_table[name] = g;
  return g;
}

int Table::find(string name){
  map<string,Mptr>::iterator m_it;
  map<string,Gptr>::iterator g_it;
  m_it = obj_table.find(name);
  g_it = grp_table.find(name);
  if (m_it != obj_table.end())
    return 1;
  else if(g_it != grp_table.end())
    return 2;
  else {
    return 0;
  }
}

void Table::play(string _name, ostream& s){
  switch (find(_name)){
      case 1:
      	s << "Objet en cours d'affichage..." << endl;
        obj_table[_name]->play();
        break;
      case 2:
        s << "On ne peut pas jouer car il s'agit d'un groupe" << endl;
        break;
      case 0:
        s << "L'objet n'est pas dans la table" << endl;
        break;
  }
}

void Table::deleteByName(string _name,ostream& s){
  
  if (find(_name) == 1){
    obj_table.erase(_name);
    s << "Suppression de l'objet " << _name << " dans la table des objets" << endl;
  } 
  else{ 
  	for (auto it : grp_table){	
      		if (grp_table[it.first]->find(_name)){
        		string grp_name = grp_table[it.first]->getName();
			grp_table[it.first]->removeMediaByName(_name);
        		s << "L'objet de nom : " << _name << " qui se trouvait dans le groupe " << grp_name << " vient d'être détruit" << endl;
       		}
  	}
  }
 
}



void Table::displayAll(ostream& s){

	s << "Contenu de la table des objets : ";
	for (auto it : obj_table){
		s << it.first + " ";
	}
	s << endl;
	for (auto it : grp_table){
		s << "Le groupe de nom : " << it.first << " contient: " << grp_table[it.first]->affiche() << endl;
	}
}

void Table::affiche(string name, ostream& s){
	switch(find(name)){
		case 1:
			obj_table[name]->affiche(s); 
			break;
		case 0:
			s << "L'objet n'est pas dans la table...";
			break;
	}
}

Table::~Table(){
  obj_table.erase(obj_table.begin(),obj_table.end());
  grp_table.erase(grp_table.begin(),grp_table.end());
}
