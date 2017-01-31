#include "groupe.h"
#include <iostream>

void Groupe::addMedia(Mptr media){
  push_back(media);
}

void Groupe::removeMedia(Mptr media){
  iterator it;
  for(pList::iterator it = begin(); it != end(); ++it){
    if ((*it)->getName() == media->getName())
      erase(it);
      cout << (*it)->getName() << " vient d'être détruit" << endl;
      it->reset();
  }
}

void Groupe::removeMediaByName(string _name){
  iterator it;
  for(pList::iterator it = begin(); it != end(); ++it){
    if ((*it)->getName() == _name)
      erase(it);
      cout << (*it)->getName() << " vient d'être détruit du groupe de nom : " << name << endl;
      it->reset();
  }
}

bool Groupe::find(string _name){
  iterator it;
  for(pList::iterator it = begin(); it != end(); ++it){
    if ((*it)->getName() == _name)
      return true;
  }
  return false;
}

void Groupe::affiche(){
  cout << "Le groupe contient :";
  for(pList::iterator it = begin(); it != end(); ++it){
    cout << " " << (*it)->getName();
  }
  cout << endl;
}

Groupe::~Groupe() {
  for(pList::iterator it = begin(); it != end(); ++it)
    it->reset();
  cout << "Tous les éléments de la liste ne pointent maintenant sur rien !" << endl;
}
