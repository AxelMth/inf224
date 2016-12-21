#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <string>
#include "video.h"

class Film : public Video {
  private:
    int number_chapter;
    int * tab = new int[number_chapter];
  public:
    Film(string name = "Défault name", string path = "Default path", int total_length = 0, int number_chapter = 0, int * tab = 0);
    void setTab(const int * tab, int tab_length);
    virtual int * getTab() const;
    virtual inline int getNumberChapter() const {return number_chapter;}
    virtual void affiche();
    virtual ~Film(){};
};

#endif
