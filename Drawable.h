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

//	virtual void drawShape() = 0;

protected:
	const Display display;
};


#endif