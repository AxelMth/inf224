#include "multimedia.h"
#include <list>

typedef list<Multimedia*> MultimediaPtr;

class Groupe : public MultimediaPtr {
  private :
    string name;
  public:
    Groupe(string name) : name(name){};
    string inline getName() {return name;};
    void addMedia(Multimedia * media);
    void removeMedia(Multimedia * media);
    void printGroupe(ostream& cout);
};
