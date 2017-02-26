//#define VERSION_TEST
//#include "afficheur.h"
#include <string>
#include <iostream>
#include <fstream>
#include "photo.h"
#include "video.h"
#include "multimedia.h"
#include "film.h"
#include "table.h"
using namespace std;

typedef shared_ptr<Photo> Pptr;
typedef shared_ptr<Video> Vptr;
typedef shared_ptr<Film> Fptr;
typedef shared_ptr<Groupe> Gptr;



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
    }

    int tab[15];
    for(int j = 0; j < 15; j++){
      tab[j] = 1;
    }

    Film * film = new Film("Film","path",1500,15,(int *) tab);

    film->affiche();

    tab[14] = 6;

    printf("La 14ème valeur de tab2 est : %d\n",tab[14]);

    film->affiche();

    int * tab2 = {0};
    tab2 = film->getTab();

    tab2[3] = 6;
    //printf("La 3ème valeur de tab2 est maintenant : %d\n",tab2[3]);

    film->affiche();
    int i;
    for (i = 0; i < 15; i++)
      printf("tab(%d) = %d\n",i,tab2[i]);
    delete film;*/


    /*Groupe * gp = new Groupe("Photos");
    shared_ptr<Photo> p(new Photo("Anna","~/Pictures/Numériser.jpeg",0,0));
    gp->addMedia(p);
    gp->printGroupe(cout);
    p->display();
    gp->removeMedia(p);
    gp->printGroupe(cout);
    //p->display(); // Segmentation Fault
    delete gp;
    //p->display("~/Pictures/Numériser.jpeg");*/
    /*Table * t = new Table();
    shared_ptr<Photo> p(new Photo("Photo","Path",0,0));
    shared_ptr<Photo> ph = t->createPhoto("Photo","~/Images/Photo.jpg",0,0);
    shared_ptr<Video> v = t->createVideo("video","~/Vidéos/Video.mp4",350);
    //ph->play();
    shared_ptr<Groupe> g = t->createGroupe("Nom du Groupe");
    g->addMedia(p);
    t->play("Photo");
    t->play("video");
    delete t;*/

    /*Table * t = new Table();
    shared_ptr<Photo> v = t->createPhoto("Video","~/Images/photo1.jpg",0,0);
    v->display();

    Gptr g1 = t->createGroupe("Groupe 1");
    Gptr g2 = t->createGroupe("Groupe 2");
    //shared_ptr<Photo> p(new Photo("Photo 1","Path"));
    //œg1->addMedia(p);
    Pptr p = t->createPhoto("Photo","~/Images/Photo.jpg",0,0);
    t->play("Photo");
    //bool flag = g1->find("Photo 1");
    //printf("%d\n",flag);
    //flag = g2->find("Photo 1");
    //printf("%d\n",flag);
    //t->deleteByName("Groupe 1");
    delete t;*/
/*	 	Table * t = new Table();
	  shared_ptr<Photo> photo = t->createPhoto("Paysage","~/Images/Paysage.jpg",0,0);
	  shared_ptr<Photo> photo1 = t->createPhoto("Elephant","~/Images/Elephant.png",0,0);
	  shared_ptr<Photo> photo2 = t->createPhoto("PieChart","~/Images/PieChart.jpg",0,0);
	  shared_ptr<Video> video = t->createVideo("Tuning","~/Videos/video1.mp4",15);
	  int tab[2] = {1,2};
	  shared_ptr<Film> film = t->createFilm("Tuning","~/Videos/video1.mp4",15,2,tab);


	  shared_ptr<Groupe> wallpaper = t->createGroupe("Fond d'écran");
	  wallpaper->addMedia(photo);

	  shared_ptr<Groupe> other = t->createGroupe("Autres");
	  other->addMedia(photo1);
	  other->addMedia(photo2);
	  other->addMedia(video);
	  other->addMedia(film);

	 	other->removeMediaByName("Elephant");
		string result = other->affiche();
		printf(result.c_str());
		delete t;
*/

		Table * t = new Table();
		/*shared_ptr<Photo> photo = t->createPhoto("Paysage","~/Images/Paysage.jpg",0,0);
		shared_ptr<Photo> photo1 = t->createPhoto("Elephant","~/Images/Elephant.png",0,0);
		shared_ptr<Photo> photo2 = t->createPhoto("PieChart","~/Images/PieChart.jpg",0,0);
		shared_ptr<Video> video = t->createVideo("Tuning","~/Videos/video1.mp4",15);
		*/
		int tab[2] = {1,2};
		shared_ptr<Film> film = t->createFilm("Tuning","~/Videos/video1.mp4",15,2,tab);
		/*ostream f("Sérial.txt"); // f(fileName.c_str()) avant C++11
 		if (!f) {
 			cerr << "Can't open file " << fileName << endl;
 		}
		photo1->write(f);
		delete t;*/
		t->play("Elephant",cout);

		delete t;

    return 0;
}
