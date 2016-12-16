#ifndef PHOTO_H
#define PHOTO_H

#include "multimedia.h"
#include <string>

class Photo : public Multimedia
{
	private:
			double longitude;
			double latitude;
	public:
		Photo();
		~Photo();
		Photo(string name, string path) : Multimedia(name, path){};
		//Photo(string name="None", string path="None", double longitude = 0.0, double latitude = 0.0);
		virtual void display (string path) const;

};

#endif
