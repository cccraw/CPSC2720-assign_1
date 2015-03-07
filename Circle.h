#ifndef CIRCLE_H
#define CIRCLE_H

#include "Drawable.h"
#include "Movable.h"
#include "Vector.h"
#include "Display.h"
#include <allegro5/allegro_primitives.h>

class Circle : public Drawable, public Movable {
public:
	Circle(const Display &dis, int fps, int rad) :
		Drawable(dis), origin(-1, 555-(2*rad)), crtSpeed(200, 0), radius(rad)	{
		width = dis.getW(); height = dis.getH();

	};

		//~Circle();

		void updateShape(double dt) {
			Point newOrigin = origin + crtSpeed*dt;
			if (newOrigin.x > width + radius) {
				newOrigin.x = newOrigin.x - width - 2 * radius;
			}

			//not needed for this program but want to keep

			/*if (newOrigin.x < 0 - radius){
				newOrigin.x = newOrigin.x + width + 2 * radius;
			}

			if (newOrigin.y > height + radius){
				newOrigin.y = newOrigin.y - height - 2 * radius;
			}

			if (newOrigin.y < 0 - radius) {
				newOrigin.y = newOrigin.y + height + 2 * radius;
			}*/



			origin = newOrigin;
		}

		void drawShape(){
			al_draw_circle(
				static_cast<int>(origin.x),
				static_cast<int>(origin.y),
				radius,
				colr,
				sz);
		}

	
private:

	Point origin; // the origin of the Circle
	Vector crtSpeed; // speed in pixels per sec
	int width, height; // of the window
	float radius; // of the circle
	ALLEGRO_COLOR colr = getColor();
	int sz = rand() % 15;
	
};


#endif