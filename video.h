#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include "multimedia.h"

class Video : public Multimedia
{
	protected:
		int total_length; // en secondes
	public:
		Video(string name, string path) : Multimedia(name, path){};
		Video(string name="None", string path="None", int total_length = 0);
		virtual void play () override;
		virtual ~Video() {};
		virtual void affiche() override;
};

#endif
