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

void Table::find(string name){
  map<string,Mptr>::iterator m_it;
  map<string,Gptr>::iterator g_it;
  m_it = obj_table.find(name);
  g_it = grp_table.find(name);
  if (m_it != obj_table.end())
    obj_table[name]->affiche();
  else if(g_it != grp_table.end())
    grp_table[name]->affiche();
  else cout << "Aucun objet ne correspond à la recherche !" << endl;
}
