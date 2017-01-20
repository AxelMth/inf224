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
    Multimedia(){};
    Multimedia(string name,string path);
    virtual void setName(string name);
    virtual void setPath(string path);
    virtual string getName();
    virtual string getPath();
    virtual void play() = 0;
    virtual inline ~Multimedia(){};
    virtual void affiche() = 0;
};
#endif // MULTIMEDIA_H
