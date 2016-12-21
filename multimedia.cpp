#include "multimedia.h"

Multimedia::Multimedia(string _name, string _path){
    name = _name;
    path = _path;
}

string Multimedia::getName(){
    return name;
}

string Multimedia::getPath(){
    return path;
}

void Multimedia::setName(string _name){
    name = _name;
}

void Multimedia::setPath(string _path){
    path = _path;
}
