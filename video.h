#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include "multimedia.h"

class Video : public Multimedia
{
	protected:
		Video(string name, string path, int total_length = 0) : Multimedia(name, path), total_length(total_length){};
		int total_length; // en secondes
	public:
		friend class Table;
		virtual void play () override;
		virtual ~Video() {};
		virtual void affiche(ostream& s) override;
};

#endif
