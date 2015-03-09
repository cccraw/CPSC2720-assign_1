#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "Display.h"
#include <allegro5/allegro.h>

class Drawable
{
public:
	Drawable(const Display &dis) : display(dis) {
	}

	//~Drawable();

	virtual void drawShape() = 0;

	ALLEGRO_COLOR getColor(){
		int r, g, b;
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;
		return al_map_rgb(r, g, b);
	}


protected:
	const Display display;
};


#endif