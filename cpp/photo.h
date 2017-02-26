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
	protected:
		Photo(string name = "Default", string path = "Default", double longitude = 0.0, double latitude = 0.0) : Multimedia(name, path), longitude(longitude), latitude(latitude) {} ;
	public:
		friend class Table;
		void affiche(ostream& s) override;
		void play() override;
		void write(ostream& f) override;
		void read(istream& f) override;
		virtual ~Photo() {};
};

#endif
