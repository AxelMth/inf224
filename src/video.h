#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"
#include <string>

class Video : public Multimedia
{
	protected:
			int total_length; // en secondes
	public:
		//Video(){};
		Video(string name, string path) : Multimedia(name, path){};
		Video(string name="None", string path="None", int total_length = 0);
		virtual void display (string path) const;
		~Video(){};
};

#endif
