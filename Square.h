#ifndef SQUARE_H
#define SQUARE_H

#include "Drawable.h"
#include "Movable.h"
#include "Vector_t.h"
#include "Display.h"
#include <allegro5/allegro_primitives.h>
#include <Vector>
#include <cmath>
#include <memory>
//#include <iostream> //for troubleshooting

class Square : public Drawable, public Movable
{
public:
	Square(const Display &dis, int fps, int sqSz, shared_ptr<Ground> grPtr) :
		Drawable(dis), grdPtr(grPtr), squareSize(sqSz)	{
		indexPt = 0;
		int startIndex = rand() % grdPtr->groundPts.size(); //bad when starting at last point
		origin = grdPtr->groundPts[startIndex];
		indexPt = lastpt = startIndex;
		goal = startIndex + 1;
	};

//	~Square(){};

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
		origin.x = (origin.x + (slope.x * dt)); //move the shape x
		origin.y = (origin.y + (slope.y * dt)); //move the shape y


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
		al_draw_rectangle(origin.x,
			origin.y,
			origin.x - squareSize,
			origin.y - squareSize,
			colr,
			sz);
	}

private:
	Vector_t origin; // the origin of the Circle
	int indexPt;
	int goal = 1;
	int lastpt = 0;
	Vector_t slope;
	Vector_t crtSpeed; // speed in pixels per sec
	int squareSize; // of the drawn block in pixels
	ALLEGRO_COLOR colr = getColor();
	int sz = (rand() % 15) + 5;
	//vector<Vector_t> groundPts;
	shared_ptr<Ground> grdPtr;

};


#endif