#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <string>
#include "video.h"

class Film : public Video {
  private:
  	int number_chapter;
    	int * tab = new int[number_chapter];
  protected:
  	Film(string name = "Défault name", string path = "Default path", int total_length = 0, int number_chapter = 0, int * tab = 0);
  public:
    	friend class Table;
	void setTab(const int * tab, int tab_length);
   	virtual const int * getTab(int number_chapter) const {return tab;};
    	void affiche(ostream& s);
    	void print_tab();
    	virtual ~Film(){delete [] tab;};
};

#endif
