#define errmsg "Attention, valeur de la taille trop grande par rapport aux nombre de chapitre !"
#include "film.h"

Film::Film(string name, string path, int total_length, int number_chapter, int * _tab) : Video(name,path,total_length), number_chapter(number_chapter) {
  for (int i = 0 ; i < number_chapter ; i++)
    tab[i] = _tab[i];
}

void Film::setTab(const int * _tab, int tab_length){

  if (tab_length > number_chapter){
    cerr << errmsg << endl;
    exit(2);
  }

  int i;
  for (i =0; i < tab_length ; i++)
    tab[i] = _tab[i];
}

void Film::affiche(){

  int i;
  for (i = 0; i < number_chapter; i++)
      printf("La durée du chapitre numéro %d est de %d secondes.\n",i,tab[i]);

}

int * Film::getTab() const {
  int * _tab = new int(number_chapter);

  for (int i = 0; i < number_chapter; i++)
    _tab[i] = tab[i];

  return _tab;
}
