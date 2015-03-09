/// The Ground is drawen in the lower 1/3 of the screen
#ifndef GROUND_H
#define GROUND_H

#include "Display.h"
#include "Drawable.h"
#include "Vector.h"
#include <cstdlib>
#include <ctime>
#include <list>
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
	friend class Simulate;

	Ground(const Display &dis) : display(dis), Drawable(dis) {
		grlist();
	}

	void drawShape(){
	//	al_draw_line(groundPts.front().x, groundPts.front().y, groundPts.front().x, groundPts.front().y, colr, 3);
		al_draw_line(-100, 550, 100, 500, al_map_rgb(255, 100, 100), 3);
		al_draw_line(100, 500, 200, 555, al_map_rgb(255, 100, 100), 3);
		al_draw_line(200, 555, 300, 480, al_map_rgb(255, 100, 100), 3);
		al_draw_line(300, 480, 400, 450, al_map_rgb(255, 100, 100), 3);
		al_draw_line(400, 450, 500, 580, al_map_rgb(255, 100, 100), 3);
		al_draw_line(500, 580, 600, 510, al_map_rgb(255, 100, 100), 3);
		al_draw_line(600, 510, 700, 400, al_map_rgb(255, 100, 100), 3);
		al_draw_line(700, 400, 900, 550, al_map_rgb(255, 100, 100), 3);
	}

	void grlist(){
		Vector grdpt1(-100, 550);
		Vector grdpt2(100, 500);
		Vector grdpt3(100, 500);
		Vector grdpt4(200, 555);
		Vector grdpt5(200, 555);
		Vector grdpt6(300, 480);
		Vector grdpt7(300, 480);
		Vector grdpt8(400, 450);
		Vector grdpt9(400, 450);
		Vector grdpt10(500, 580);
		Vector grdpt11(500, 580);
		Vector grdpt12(600, 510);
		Vector grdpt13(600, 510);
		Vector grdpt14(700, 400);
		Vector grdpt15(700, 400);
		Vector grdpt16(900, 550);

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


	//~Ground();

protected:
	const Display display;
	ALLEGRO_COLOR colr = getColor();
	list<Vector> groundPts;
};


#endif