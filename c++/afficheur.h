#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <iostream>

using namespace std;

class Afficheur
{
public:
    Afficheur() {};
    virtual void affiche (ostream& cout, string message);
    virtual ~Afficheur() {};
};

#endif // AFFICHEUR_H
