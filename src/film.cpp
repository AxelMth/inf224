#include "film.h"

void Film::setTab (int _tab[], int tab_length){

  if (tab_length != number_chapter)
    exit(2);

  int i;
  for (i =0; i<tab_length ; i++)
    tab[i] = _tab[i];

}

int* Film::getTab(){

  int result[number_chapter];

  int i;
  for (i = 0; i < number_chapter ; i++)
      result[i] = tab[i];

  return result;
  
}
