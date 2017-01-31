#include "photo.h"
#include "multimedia.h"
#include "video.h"
#include "film.h"
#include "groupe.h"
#include <map>

typedef shared_ptr<Multimedia> Mptr;
typedef shared_ptr<Photo> Pptr;
typedef shared_ptr<Video> Vptr;
typedef shared_ptr<Film> Fptr;
typedef map<string,Mptr> MMap;
typedef shared_ptr<Groupe> Gptr;
typedef map<string,Gptr> GMap;

class Table{
private:
  MMap obj_table;
  GMap grp_table;
public:
  friend class Photo;
  friend class Video;
  friend class Groupe;
  friend class Film;
  Table(){};
  friend Photo::Photo(string name, string path, double longitude = 0.0, double latitude = 0.0);
  Pptr createPhoto(string name, string path, double longitude, double latitude);
  Vptr createVideo(string name, string path, int length);
  Fptr createFilm(string name, string path, int length, int number_chapter, int * tab);
  Gptr createGroupe(string name);
  int find(string name);
  void play(string name);
  //void deleteByName(string name);
  virtual ~Table();
};
