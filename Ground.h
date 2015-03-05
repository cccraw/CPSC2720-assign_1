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

		Point_t *temp = new Point_t(-1, 550);
		ground_vertex.push_back(*temp);
		delete temp;
		temp = new Point_t(100, 500);
		ground_vertex.push_back(*temp);
		delete temp;
		temp = new Point_t(200, 550);
		ground_vertex.push_back(*temp);
		delete temp;
		temp = new Point_t(300, 480);
		ground_vertex.push_back(*temp);
		delete temp;
		temp = new Point_t(400, 450);
		ground_vertex.push_back(*temp);
		delete temp;
		temp = new Point_t(500, 580);
		ground_vertex.push_back(*temp);
		delete temp;
		temp = new Point_t(600, 510);
		ground_vertex.push_back(*temp);
		delete temp;
		temp = new Point_t(700, 400);
		ground_vertex.push_back(*temp);
		delete temp;
		temp = new Point_t(801, 550);
		ground_vertex.push_back(*temp);
		delete temp;

		//attempt at making a random ground

		//while (ground_vertex.back().x < display.getW()){
		//	Point_t *dot = new Point_t();
		//	ground_vertex.push_back(*dot);
		//	delete dot;
		//}



		//Point_t *dot = new Point_t();
		//ground_vertex.push_back(*dot);
		//while (ground_vertex.back().x < display.getW()) {
		//	//int temp_x = ground_vertex.back().x;
		//	if (dot->x < ground_vertex.back().x) {
		//		delete dot;
		//		dot = new Point_t();
		//	}
		//	else {
		//		ground_vertex.push_back(*dot);
		//		delete dot;
		//		dot = new Point_t();
		//	}
		//}
		//delete dot;
	}

	void drawShape(){
		while (ground_vertex.size() != 0) {
			float x1 = ground_vertex.front().x;
			float y1 = ground_vertex.front().y;
			ground_vertex.pop_front();
			float x2 = ground_vertex.front().x;
			float y2 = ground_vertex.front().y;
			ground_vertex.pop_front();

			al_draw_line(x1, y1, x2, y2, colr, 10);
		}
	}

	ALLEGRO_COLOR getColor(){
		int r, g, b;
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;
		return al_map_rgb(r, g, b);
	}

	//~Ground();

protected:
	const Display display;
	//Point_t *dot;
	list<Point_t> ground_vertex;
	ALLEGRO_COLOR colr = getColor();
};


#endif