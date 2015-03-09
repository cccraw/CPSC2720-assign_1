#ifndef CIRCLE_H
#define CIRCLE_H

#include "Drawable.h"
#include "Movable.h"
#include "Vector.h"
#include "Display.h"
#include <allegro5/allegro_primitives.h>
#include <list>
#include <cmath>
#include <memory>

class Circle : public Drawable, public Movable {
public:
	Circle(const Display &dis, int fps, int rad) :
		Drawable(dis), origin(-1, 555 - (2 * rad)), crtSpeed(200, 0), radius(rad)	{
		width = dis.getW(); height = dis.getH();
		bldLst();
	};

	//~Circle();

	void updateShape(double dt) {
		Point newOrigin = origin + crtSpeed*dt;
		double length = sqrt(newOrigin.x * newOrigin.x + newOrigin.y * newOrigin.y);
		double angle = atan2(newOrigin.y, newOrigin.x) * 180 / 3.14159265;
		Point target(xPts.front(), yPts.front());

		bool newTarget = true;
		

		////if list is exausted
		if (xPts.front() == xPts.back())
			bldLst();
		/*		//if circle leaves edge of screen
		//not needed for this program but want to keep


		if (newOrigin.x > width + radius) {
			newOrigin.x = newOrigin.x - width - 2 * radius;
		}
		if (newOrigin.x < 0 - radius){
		newOrigin.x = newOrigin.x + width + 2 * radius;
		}

		if (newOrigin.y > height + radius){
		newOrigin.y = newOrigin.y - height - 2 * radius;
		}

		if (newOrigin.y < 0 - radius) {
		newOrigin.y = newOrigin.y + height + 2 * radius;
		}*/


		// new target when needed
		if (newTarget){
			target.x = xPts.front();
			target.y = yPts.front();
			xPts.pop_front();
			yPts.pop_front();
			newTarget = false;
		}

		//move circle
		newOrigin.x += length*cos(angle);
		newOrigin.y += length*sin(angle);

		//if circle reached end of line, set new target
		if (abs(newOrigin.x - target.x) + abs(newOrigin.y - target.y) < al_itofix(10))
			newTarget = true;

		//draw circle, done in Simulate
		origin = newOrigin;

		//calculate angle from circle to next point on line
		angle = atan2(target.y - newOrigin.y, target.x - newOrigin.x);

		

	}

	void drawShape(){
		al_draw_circle(
			origin.x,
			origin.y,
			radius,
			colr,
			sz);
	}

	void bldLst(){//can figure out how else to add items to the list. I probably dont even need it
		// 550, 500, 500, 555, 555, 480, 480, 450, 450, 580, 580, 510, 510, 400, 400, 550
		yPts.push_back(550);
		yPts.push_back(500);
		yPts.push_back(500);
		yPts.push_back(555);
		yPts.push_back(555);
		yPts.push_back(480);
		yPts.push_back(480);
		yPts.push_back(450);
		yPts.push_back(450);
		yPts.push_back(580);
		yPts.push_back(580);
		yPts.push_back(510);
		yPts.push_back(510);
		yPts.push_back(400);
		yPts.push_back(400);
		yPts.push_back(550);

		//-100, 100, 100, 200, 200, 300, 300, 400, 400, 500, 500, 600, 600, 700, 700, 900,
		xPts.push_back(-100);
		xPts.push_back(100);
		xPts.push_back(100);
		xPts.push_back(200);
		xPts.push_back(200);
		xPts.push_back(300);
		xPts.push_back(300);
		xPts.push_back(400);
		xPts.push_back(400);
		xPts.push_back(500);
		xPts.push_back(500);
		xPts.push_back(600);
		xPts.push_back(600);
		xPts.push_back(700);
		xPts.push_back(700);
		xPts.push_back(900);


	}

private:
	list<double> yPts;
	list<double> xPts;
	Point origin; // the origin of the Circle
	Vector crtSpeed; // speed in pixels per sec
	int width, height; // of the window
	float radius; // of the circle
	ALLEGRO_COLOR colr = getColor();
	int sz = rand() % 15;

};


#endif