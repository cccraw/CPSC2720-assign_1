#ifndef CIRCLE_H
#define CIRCLE_H

#include "Drawable.h"
#include "Movable.h"
#include "Vector.h"
#include "Display.h"

class Circle : public Drawable, public Movable
{
public:
	Circle(const Display &dis, int fps, int rad);

	~Circle();

	void updateShape(double);

	void drawShape();

private:
	Point origin; // the origin of the Circle
	Vector crtSpeed; // speed in pixels per sec
	int width, height; // of the window
	float radius; // of the circle
};


#endif