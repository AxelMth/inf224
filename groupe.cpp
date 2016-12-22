#include "groupe.h"
#include <iostream>

void Groupe::addMedia(Multimedia * media){
  push_back(media);
}

void Groupe::removeMedia(Multimedia * media){
  iterator it;
  for(MultimediaPtr::iterator it = begin(); it != end(); ++it){
    if ((*it)->getName() == media->getName())
      erase(it);
  }
}

void Groupe::printGroupe(ostream& cout){
  cout << "my list contains :";
  for(MultimediaPtr::iterator it = begin(); it != end(); ++it){
    cout << " " << (*it)->getName();
  }
  cout << endl;
}
