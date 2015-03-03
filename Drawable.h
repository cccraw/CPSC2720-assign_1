#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "Display.h"
#include <allegro5/allegro.h>

class Drawable
{
public:
	Drawable(const Display &dis, int fps);

	~Drawable();

	virtual void updateShape(double) = 0;

protected:
};


#endif