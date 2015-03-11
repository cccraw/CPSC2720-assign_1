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
#include <iostream>//for troubleshooting

class Circle : public Drawable, public Movable {
public:
	Circle(const Display &dis, int fps, int rad, shared_ptr<Ground> grPtr) :
		Drawable(dis), grdPtr(grPtr), radius(rad)	{
		indexPt = 0;
		int startIndex = rand() % grdPtr->groundPts.size(); //bad when 15, can -1 or bad too
		origin = grdPtr->groundPts[startIndex];
		indexPt = lastpt = startIndex;
		goal = startIndex + 1;
	};


	void updateShape(double dt) {

		if (origin == grdPtr->groundPts[goal]){//if at next point on the line
			indexPt++; goal++; lastpt++;

			if (indexPt == grdPtr->groundPts.size() - 1){//if at the end of the line
				indexPt = 0;
				lastpt = 0;
				goal = 1;
				origin = grdPtr->groundPts[0];

			}
		}

		slope = grdPtr->angle[indexPt]; //get slope from vector of angles in ground
		origin = (origin + (slope * dt)); //move the shape


		if (grdPtr->groundPts[indexPt].y<grdPtr->groundPts[goal].y){
			if (origin.y > grdPtr->groundPts[goal].y) {//if shape goes beond goal point
				origin.y = grdPtr->groundPts[goal].y;
			}
		}
		if (grdPtr->groundPts[indexPt].y>grdPtr->groundPts[goal].y){
			if (origin.y < grdPtr->groundPts[goal].y) {//if shape goes beond goal point
				origin.y = grdPtr->groundPts[goal].y;
			}
		}

		if (origin.x > grdPtr->groundPts[goal].x) {//if shape goes beond goal point
			origin.x = grdPtr->groundPts[goal].x;
		}
	}

	void drawShape(){
		al_draw_circle(
			origin.x,
			origin.y-radius,
			radius,
			colr,
			sz);
	}

private:
	Vector_t origin; // the origin of the Circle
	int indexPt;
	int goal = 1;
	int lastpt=0;
	Vector_t slope;
	Vector_t crtSpeed; // speed in pixels per sec
	float radius; // of the circle
	ALLEGRO_COLOR colr = getColor();
	int sz = (rand() % 15)+5;
	//vector<Vector_t> groundPts;
	shared_ptr<Ground> grdPtr;
};


#endif