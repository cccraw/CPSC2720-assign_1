#ifndef CIRCLE_H
#define CIRCLE_H

#include "Drawable.h"
#include "Movable.h"
#include "Vector_t.h"
#include "Display.h"
#include <allegro5/allegro_primitives.h>
#include <Vector>
#include <cmath>
#include <memory>

class Circle : public Drawable, public Movable {
public:
	Circle(const Display &dis, int fps, int rad, shared_ptr<Ground> grPtr) :
		Drawable(dis), origin(-1, 550), crtSpeed(200, 0), radius(rad), grdPtr(grPtr)	{
		width = dis.getW(); height = dis.getH();
		grVector_t();
	};

	//~Circle();

	void updateShape(double dt) {
		Point newOrigin = origin + crtSpeed*dt;
		
		static int elem = 0;
		if (newOrigin.x > groundPts.at(elem).x) {
			int i = groundPts.size();
			angle.x = groundPts.at(elem + 1).x - groundPts.at(elem).x;
			angle.y = groundPts.at(elem + 1).y - groundPts.at(elem).y;
			elem++;
			if (elem >= 15)
				elem = 0;
		}

		newOrigin.x += angle.x*dt;
		newOrigin.y += angle.y*dt;

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

	void grVector_t(){
		Vector_t grdpt1(-100, 550);
		Vector_t grdpt2(100, 500);
		Vector_t grdpt3(100, 500);
		Vector_t grdpt4(200, 555);
		Vector_t grdpt5(200, 555);
		Vector_t grdpt6(300, 480);
		Vector_t grdpt7(300, 480);
		Vector_t grdpt8(400, 450);
		Vector_t grdpt9(400, 450);
		Vector_t grdpt10(500, 580);
		Vector_t grdpt11(500, 580);
		Vector_t grdpt12(600, 510);
		Vector_t grdpt13(600, 510);
		Vector_t grdpt14(700, 400);
		Vector_t grdpt15(700, 400);
		Vector_t grdpt16(900, 550);

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
	Point angle;
	Vector_t crtSpeed; // speed in pixels per sec
	int width, height; // of the window
	float radius; // of the circle
	ALLEGRO_COLOR colr = getColor();
	int sz = rand() % 20;
	vector<Vector_t> groundPts;
	shared_ptr<Ground> grdPtr;
};


#endif