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
		virtual ~Photo() {};
		Photo(string name, string path, double longitude = 0.0, double latitude = 0.0) : Multimedia(name, path), longitude(longitude), latitude(latitude) {};
		//Photo(string name="None", string path="None", double longitude = 0.0, double latitude = 0.0);
		void affiche() override;
		void display() override;

};

#endif
