#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>

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
    virtual void display(string path) const = 0;
    virtual ~Multimedia(){};
};
#endif // MULTIMEDIA_H
