#ifndef CIRCLE_H
#define CIRCLE_H

#include "Drawable.h"
#include "Movable.h"
#include "Vector.h"
#include "Display.h"
#include <allegro5/allegro_primitives.h>
#include <Vector>
#include <cmath>
#include <memory>

class Circle : public Drawable, public Movable {
public:
	Circle(const Display &dis, int fps, int rad, shared_ptr<Ground> grPtr) :
		Drawable(dis), origin(-1, 555), crtSpeed(200, 0), radius(rad)	{
		width = dis.getW(); height = dis.getH();



	};

	//~Circle();

	void updateShape(double dt) {
		Point newOrigin = origin + crtSpeed*dt;

		//if circle leaves edge of screen
		//not needed for this program but want to keep
		//if (newOrigin.x > width + radius) {
		//	newOrigin.x = newOrigin.x - width - 2 * radius;
		//}
		//if (newOrigin.x < 0 - radius){
		//newOrigin.x = newOrigin.x + width + 2 * radius;
		//}
		//if (newOrigin.y > height + radius){
		//newOrigin.y = newOrigin.y - height - 2 * radius;
		//}
		//if (newOrigin.y < 0 - radius) {
		//newOrigin.y = newOrigin.y + height + 2 * radius;
		//}



		origin = newOrigin;
	}

	void drawShape(){
		al_draw_circle(
			origin.x,
			origin.y,
			radius,
			colr,
			sz);
	}

	//void getOrigin(){
	//	int randStart = (rand() % groundPts->size());
	//	origin = groundPts->pointAtIndex(randStart);
	//	goal = groundPts->pointAtIndex(randStart + 1);
	//}

	void grVector(){
		Point grdpt1(-100, 550);
		Point grdpt2(100, 500);
		Point grdpt3(100, 500);
		Point grdpt4(200, 555);
		Point grdpt5(200, 555);
		Point grdpt6(300, 480);
		Point grdpt7(300, 480);
		Point grdpt8(400, 450);
		Point grdpt9(400, 450);
		Point grdpt10(500, 580);
		Point grdpt11(500, 580);
		Point grdpt12(600, 510);
		Point grdpt13(600, 510);
		Point grdpt14(700, 400);
		Point grdpt15(700, 400);
		Point grdpt16(900, 550);

		groundPts.push_back(grdpt1);
		groundPts.push_back(grdpt2);
		groundPts.push_back(grdpt3);
		groundPts.push_back(grdpt4);
		groundPts.push_back(grdpt5);
		groundPts.push_back(grdpt6);
		groundPts.push_back(grdpt7);
		groundPts.push_back(grdpt8);
		groundPts.push_back(grdpt9);
		groundPts.push_back(grdpt10);
		groundPts.push_back(grdpt11);
		groundPts.push_back(grdpt12);
		groundPts.push_back(grdpt13);
		groundPts.push_back(grdpt14);
		groundPts.push_back(grdpt15);
		groundPts.push_back(grdpt16);
	}

private:
	Point origin; // the origin of the Circle
	Point goal;
	Vector crtSpeed; // speed in pixels per sec
	int width, height; // of the window
	float radius; // of the circle
	ALLEGRO_COLOR colr = getColor();
	int sz = rand() % 15;
	list<Point> groundPts;
};


#endif