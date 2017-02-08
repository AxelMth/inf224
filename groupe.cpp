#include "groupe.h"
#include <iostream>

void Groupe::addMedia(Mptr media){
  push_back(media);
}

void Groupe::removeMedia(Mptr media){
  pList::iterator toDelete;
  for(pList::iterator it = begin(); it != end(); ++it){
    if ((*it)->getName() == media->getName())
      toDelete = it;
      //cout << (*it)->getName() << " vient d'être détruit" << endl;
      //it->reset();
  }
  erase(toDelete);
}

void Groupe::removeMediaByName(string _name){
  pList::iterator toDelete;
  for(pList::iterator it = begin(); it != end(); ++it){
    if ((*it)->getName() == _name){
      toDelete = it;
    }
  }
  erase(toDelete); 
}

bool Groupe::find(string _name){
  for(pList::iterator it = begin(); it != end(); ++it){
    if ((*it)->getName() == _name)
      return true;
  }
  return false;
}

string Groupe::affiche(){
  string result;
  for(pList::iterator it = begin(); it != end(); ++it){
    result += (*it)->getName() + " ";
  }
  return result;
}

Groupe::~Groupe() {
  for(pList::iterator it = begin(); it != end(); ++it)
    it->reset();
  cout << "Tous les éléments de la liste ne pointent maintenant sur rien !" << endl;
}
