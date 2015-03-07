/// The Ground is drawen in the lower 1/3 of the screen
#ifndef GROUND_H
#define GROUND_H

#include "Display.h"
#include "Drawable.h"
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


	}

	void drawShape(){
		al_draw_line(-1, 550, 100, 500, al_map_rgb(255, 100, 100), 3);
		al_draw_line(100, 500, 200, 555, al_map_rgb(255, 100, 100), 3);
		al_draw_line(200, 555, 300, 480, al_map_rgb(255, 100, 100), 3);
		al_draw_line(300, 480, 400, 450, al_map_rgb(255, 100, 100), 3);
		al_draw_line(400, 450, 500, 580, al_map_rgb(255, 100, 100), 3);
		al_draw_line(500, 580, 600, 510, al_map_rgb(255, 100, 100), 3);
		al_draw_line(600, 510, 700, 400, al_map_rgb(255, 100, 100), 3);
		al_draw_line(700, 400, 801, 550, al_map_rgb(255, 100, 100), 3);
	}



	//~Ground();

protected:
	const Display display;
	//Point_t *dot;
	list<Point_t> ground_vertex;
	ALLEGRO_COLOR colr = getColor();
};


#endif