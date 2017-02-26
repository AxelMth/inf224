#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

using namespace std;

class Multimedia
{
protected:
    string name, path;
//private:
  //  void *operator new (size_t size) = delete;
public:
    Multimedia(string name,string path) : name(name), path(path){};
    virtual void setName(string name);
    virtual void setPath(string path);
    virtual string getName() const;
    virtual string getPath() const;
    virtual void play() = 0;
    virtual void affiche(ostream& ss) = 0;
    virtual void write(ostream& f) = 0;
    virtual void read(istream& f) = 0;
    virtual ~Multimedia(){};
};
#endif // MULTIMEDIA_H
