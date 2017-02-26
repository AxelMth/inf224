#include "multimedia.h"

string Multimedia::getName() const{
    return name;
}

string Multimedia::getPath() const{
    return path;
}

void Multimedia::setName(string _name){
    name = _name;
}

void Multimedia::setPath(string _path){
    path = _path;
}
