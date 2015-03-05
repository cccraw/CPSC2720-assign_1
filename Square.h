#ifndef SQUARE_H
#define SQUARE_H

#include "Drawable.h"
#include "Movable.h"
#include "Vector.h"
#include "Display.h"
#include <allegro5/allegro_primitives.h>

class Square : public Drawable, public Movable
{
public:
	Square(const Display &dis, int fps, int sq) :
		Drawable(dis), origin(200, 300), crtSpeed(200, 400), squareSize(sq)	{
		width = dis.getW(); height = dis.getH();
	};

//	~Square(){};

	void updateShape(double dt){
		Point newOrigin = origin + crtSpeed*dt;
		if (newOrigin.x > width + squareSize) {
			newOrigin.x = newOrigin.x - width - 2 * squareSize;
		}

		if (newOrigin.x < 0 - squareSize){
			newOrigin.x = newOrigin.x + width + 2 * squareSize;
		}

		if (newOrigin.y > height + squareSize){
			newOrigin.y = newOrigin.y - height - 2 * squareSize;
		}

		if (newOrigin.y < 0 - squareSize) {
			newOrigin.y = newOrigin.y + height + 2 * squareSize;
		}

		origin = newOrigin;
	}

	void drawShape(){
//		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_rectangle(static_cast<int>(origin.x),
			static_cast<int>(origin.y),
			static_cast<int>(origin.x) + squareSize,
			static_cast<int>(origin.y) + squareSize,
			al_map_rgb(200, 200, 0),
			2);
		//al_flip_display();
	}

private:
	Point origin; // the origin of the square
	Vector crtSpeed; // speed in pixels per sec
	int width, height; // of the window
	int squareSize; // of the drawn block in pixels
};


#endif