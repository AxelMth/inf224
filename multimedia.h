#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

using namespace std;

class Multimedia
{
protected:
    string name, path;
public:
    Multimedia(){};
    Multimedia(string name,string path);
    virtual void setName(string name);
    virtual void setPath(string path);
    virtual string getName();
    virtual string getPath();
    virtual void display() = 0;
    virtual ~Multimedia(){};
    virtual void affiche() = 0;
};
#endif // MULTIMEDIA_H
