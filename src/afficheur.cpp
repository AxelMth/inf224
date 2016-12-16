#include "afficheur.h"

using namespace std;

Afficheur::Afficheur()
{
}

void Afficheur::affiche(ostream& cout, string message){

    cout << message << endl;

}

Afficheur::~Afficheur(){}
