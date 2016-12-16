#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"
#include <string>

class Video : public Multimedia
{
	private:
			int length; // en secondes
	public:
		Video();
		~Video();
		Video(string name, string path) : Multimedia(name, path){};
		//Video(string name="None", string path="None", length = 0);
		virtual void display (string path) const;

};

#endif
