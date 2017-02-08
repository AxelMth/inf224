#define errmsg "Attention, valeur de la taille trop grande par rapport aux nombre de chapitre !"
#include "film.h"

Film::Film(string name, string path, int total_length, int number_chapter, int * _tab) : Video(name,path,total_length), number_chapter(number_chapter) {
  for (int i = 0 ; i < number_chapter ; i++)
    tab[i] = _tab[i];
}

void Film::setTab(const int * _tab, int tab_length){
  /*if (tab_length > number_chapter){
    cerr << errmsg << endl;
    exit(2);
  }*/
  int * tab2 = new int[tab_length];
  int i;
  for (i =0; i < tab_length ; i++)
    tab2[i] = _tab[i];
  tab = tab2;
  delete [] tab2;
}

void Film::print_tab(){

  int i;
  for (i = 0; i < number_chapter; i++)
      printf("La durée du chapitre numéro %d est de %d secondes.\n",i,tab[i]);

}

void Film::affiche(ostream& s){

  s << "Les attributs du film sont : " << endl;
  s << "nom: " << name << endl;
  s << "chemin: " << path << endl;
  s << "durée: " << total_length << endl;
  s << "nombre de chapitres: " << number_chapter << endl;
  s << "table des chapitres:" << endl;
  for (int i = 0;  i < number_chapter; i++){
    s << "Le chapitre numéro " << i+1 << " dure " << tab[i] << " seconde(s)" << endl;
  }

}
