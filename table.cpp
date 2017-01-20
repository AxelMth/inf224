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
    //cout << name << " appartient à la table des objets " << endl;
    return 1;
  else if(g_it != grp_table.end())
    //cout << name << " appartient à la table des groupes " << endl;
    return 2;
  else {
    //cout << "Aucun objet ne correspond à la recherche !" << endl;
    return 0;
  }
}

void Table::play(string _name){
  switch (find(_name)){
      case 1:
        obj_table[_name]->play();
        break;
      case 2:
        cout << "On ne peut pas jouer car il s'agit d'un groupe" << endl;
        break;
      case 0:
        cout << "L'objet n'est pas dans la table" << endl;
        break;
  }
}

void Table::deleteByName(string _name){
  if (find(_name)){
    obj_table.erase(_name);
    cout << "L'Objet de nom : " << _name << " vient d'être détruit." << endl;
  } else {
    for (map<string,Gptr>::iterator g_it = grp_table.begin(); g_it != grp_table.end(); ++g_it){
      if ((*g_it)->find(_name)){
        string gname = (*g_it)->getName();
        (*g_it)->removeMediaByName(_name);
        cout << "L'objet de nom : " << _name << " qui se trouvait dans le groupe " << gname << " vient d'être détruit" << endl;
      }
    }
  }
}

Table::~Table(){
  obj_table.erase(obj_table.begin(),obj_table.end());
  grp_table.erase(grp_table.begin(),grp_table.end());
}
