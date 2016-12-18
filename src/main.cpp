#include "afficheur.h"
#include <string>
#include "photo.h"
#include "video.h"
#include "multimedia.h"
#include "film.h"

using namespace std;

int main(int argc, char *argv[])
{
    /**Afficheur * afficheur = new Afficheur();
    afficheur->affiche(cout,"Hello World !");
    delete afficheur;
    string path="~/Images/photo1.jpg";
    Photo * p = new Photo("Photo1","~/Image/photo1.jpg");
    p->display(path);*
    string path = "~/Videos/video1.mp4";
    Video * v = new Video("Video1",path);
    v->display(path);
    Multimedia ** media = new Multimedia * [4];
    unsigned int count = 0;
    media[count++] = new Photo("Photo1","~/Pictures/Numériser 1.jpg");
    media[count++] = new Video("Video1","~/Videos/video1.mp4");
    media[count++] = new Photo("Photo2","~/Pictures/Numériser 2.jpg");
    media[count++] = new Video("Video2","~/Videos/video2.mp4");

    unsigned index = 0;
    for (index = 0; index<4 ; index++){
      string path;
      path = media[index]->getPath();
      media[index]->display(path);
    }*/

    Film * film = new Film("Film","path",1500);

    return 0;
}
