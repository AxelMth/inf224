#include "table.h"

Table::Table(){

    filebuf fb;
    fb.open("table.txt", ios::in);
    istream f(&fb);

   if (!f) {
     cerr << "Can't open file table.txt" << endl;
   }

   while (f) { // pas d’erreur et pas en fin de fichier

  string type;
  string name;
  string grp_name;
  bool inGroup = false;
  getline(f,type);

  if (type == "Groupe"){
    inGroup = true;
    getline(f,grp_name);
    Gptr g(new Groupe(grp_name));
    grp_table[grp_name] = g;
    getline(f,type);
  }

  if (type == "Photo"){
    Mptr p(new Photo());
    p->read(f);
    name = p->getName();
    if (!inGroup){
      obj_table[name] = p;
    }
    else {
      grp_table[grp_name]->addMedia(p);
    }
  }

  else if (type == "Video"){
    Mptr v(new Video());
    v->read(f);
    name = v->getName();
    if (!inGroup){
      obj_table[name] = v;
    }
    else {
      grp_table[grp_name]->addMedia(v);
    }
  }

  else if (type == "Film"){
    Mptr fm(new Film());
    fm->read(f);
    name = fm->getName();
    if (!inGroup){
      obj_table[name] = fm;
    }
    else {
      grp_table[grp_name]->addMedia(fm);
    }
  }
 }
 cout << "Base de données créee avec succès !" << endl;
 fb.close();
}

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
	  s << endl;
	}
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
  filebuf fb;
  fb.open ("table.txt",ios::out);
  ostream os(&fb);
  for (auto it : obj_table){
    obj_table[it.first]->write(os);
  }
  for (auto it : grp_table){
    grp_table[it.first]->write(os);
  }
  cout << "Base de données sauvegarder avec succès !" << endl;
  fb.close();
  obj_table.erase(obj_table.begin(),obj_table.end());
  grp_table.erase(grp_table.begin(),grp_table.end());
}
