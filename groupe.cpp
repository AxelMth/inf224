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
      cout << (*it)->getName() << " vient de décéder" << endl;
      it->reset();
  }
}

void Groupe::printGroupe(ostream& cout){
  cout << "my list contains :";
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
