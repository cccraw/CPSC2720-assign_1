/// The Ground is drawen in the lower 1/3 of the screen
#ifndef GROUND_H
#define GROUND_H

#include "Display.h"
#include "Drawable.h"
#include "Vector_t.h"
#include <cstdlib>
#include <ctime>
#include <Vector>
#include <allegro5/allegro_primitives.h>


using namespace std;

class Point_t{
public:
	friend class Ground;
	Point_t()
	{
		srand(time(NULL));
		x = rand() % 10;
		y = rand() % 3 + 2;
		//mod(screen height /3)
	}
	Point_t(int a, int b){
		x = a;
		y = b;
	}
protected:
	float x, y;
	//const Display display;
};


class Ground : public Drawable
{
public:
	friend class Simulate; friend class Circle; friend class Square;
	Ground(const Display &dis) : display(dis), Drawable(dis) {
		grlist();
	}

	void drawShape(){
		//for (vector<Vector_t>::iterator it = groundPts.begin(); it != groundPts.end(); it++) {
		//	al_draw_line((*it).x, (*it).y, (*it+2).x, (*it+2).y, colr, 3);
		//}
		for (int i = 0; i < groundPts.size()-1; i++) {
			al_draw_line(groundPts[i].x, groundPts[i].y, groundPts[i + 1].x, groundPts[i + 1].y, colr, 3);
		}
		//al_draw_line(-100, 550, 100, 500, al_map_rgb(255, 100, 100), 3);
		//al_draw_line(100, 500, 200, 555, al_map_rgb(255, 100, 100), 3);
		//al_draw_line(200, 555, 300, 480, al_map_rgb(255, 100, 100), 3);
		//al_draw_line(300, 480, 400, 450, al_map_rgb(255, 100, 100), 3);
		//al_draw_line(400, 450, 500, 580, al_map_rgb(255, 100, 100), 3);
		//al_draw_line(500, 580, 600, 510, al_map_rgb(255, 100, 100), 3);
		//al_draw_line(600, 510, 700, 400, al_map_rgb(255, 100, 100), 3);
		//al_draw_line(700, 400, 900, 550, al_map_rgb(255, 100, 100), 3);
	}

	void grlist(){
		//Vector_t grdpt1(-100, 550);
		//Vector_t grdpt2(100, 500);
		//Vector_t grdpt3(100, 500);
		//Vector_t grdpt4(200, 555);
		//Vector_t grdpt5(200, 555);
		//Vector_t grdpt6(300, 480);
		//Vector_t grdpt7(300, 480);
		//Vector_t grdpt8(400, 450);
		//Vector_t grdpt9(400, 450);
		//Vector_t grdpt10(500, 580);
		//Vector_t grdpt11(500, 580);
		//Vector_t grdpt12(600, 510);
		//Vector_t grdpt13(600, 510);
		//Vector_t grdpt14(700, 400);
		//Vector_t grdpt15(700, 400);
		//Vector_t grdpt16(900, 550);

		Vector_t leftPoint(-100, 400);
		groundPts.push_back(leftPoint);

		int curX = 0;
		int spacingBetween = (display.getW() / numPoints);
		for (int i = 0; i < numPoints; i++) {
			Vector_t temp(curX, ((rand() % 150) + 300));
			curX += spacingBetween;
			groundPts.push_back(temp);
		}
		Vector_t rEdge(display.getW(), 400);
		groundPts.push_back(rEdge);
		Vector_t rOfScreen(display.getW()+200, 400);
		groundPts.push_back(rOfScreen);

		//groundPts.push_back(grdpt1);
		//groundPts.push_back(grdpt2);
		//groundPts.push_back(grdpt3);
		//groundPts.push_back(grdpt4);
		//groundPts.push_back(grdpt5);
		//groundPts.push_back(grdpt6);
		//groundPts.push_back(grdpt7);
		//groundPts.push_back(grdpt8);
		//groundPts.push_back(grdpt9);
		//groundPts.push_back(grdpt10);
		//groundPts.push_back(grdpt11);
		//groundPts.push_back(grdpt12);
		//groundPts.push_back(grdpt13);
		//groundPts.push_back(grdpt14);
		//groundPts.push_back(grdpt15);
		//groundPts.push_back(grdpt16);

		for (int i = 0; i < groundPts.size() - 1; i++) {
			Vector_t tempV;
			tempV.x = groundPts[i + 1].x - groundPts[i].x;
			tempV.y = groundPts[i + 1].y - groundPts[i].y;
			angle.push_back(tempV);
		}

		//for (int j = 0; j < groundPts.size()-1; j++) {
		//	getAngle(groundPts[j], groundPts[j + 1]);
		//}
	}
	//void getAngle(Vector_t p1, Vector_t p2){
	//	for (int i = 0; i < groundPts.size() -1; i++) {
	//		Vector_t tempV;
	//		tempV.x = p2.x - p1.x;
	//		tempV.y = p2.y - p1.y;
	//		angle.push_back(tempV);
	//	}
	//}



	//~Ground();

protected:
	const Display display;
	ALLEGRO_COLOR colr = getColor();
	vector<Vector_t> groundPts;
	vector<Vector_t> angle;
	int numPoints = 20;
};


#endif