#include "multimedia.h"
#include <list>
#include <memory>

typedef shared_ptr<Multimedia> Mptr;
typedef list<Mptr> pList;

class Groupe : public pList
{
  private:
    string name;
  public:
    Groupe(string name) : name(name){};
    string inline getName() const {return name;};
    void addMedia(Mptr media);
    void removeMedia(Mptr media);
    void removeMediaByName(string name);
    bool find(string name);
    string affiche();
    ~Groupe();
};
