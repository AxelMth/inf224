#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include "multimedia.h"

using namespace std;

class Photo : public Multimedia
{
	private:
			double longitude;
			double latitude;
	public:
		virtual ~Photo();
		Photo(string name, string path) : Multimedia(name, path){};
		Photo(string name="None", string path="None", double longitude = 0.0, double latitude = 0.0);
		void display (string path) const final;

};

#endif
