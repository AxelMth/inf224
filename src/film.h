#ifndef FILM_H
#define FILM_H

#include <string>

class Film : public Video {
  private:
    int number_chapter;
    int tab[];
  public:
    //Film() : Video() {};
    Film(string name, string path, int total_length, int number_chapter = 0) : Video(name,path,total_length){};
    void setTab(int tab[], int tab_length);
    int* getTab();
    ~Film(){};
};

#endif
