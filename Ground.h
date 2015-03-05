/// The Ground is drawen in the lower 1/3 of the screen
#ifndef GROUND_H
#define GROUND_H

#include "Display.h"
#include "Drawable.h"
#include <cstdlib>
#include <ctime>
#include <list>
using namespace std;

class Point_t{
public:
	friend class Ground;
	Point_t()
	{
		srand(time(NULL));
		x = rand() % display.getW() / 10;
		y = rand() % (display.getH() / 3) + (display.getH() / 2);
		//mod(screen height /3)
	}
protected:
	float x, y;
	const Display display;
};


class Ground : public Drawable
{
public:
	friend class Simulate;

	Ground(const Display &dis) : display(dis), Drawable(dis) {
	//	while (ground_vertex.back().x < display.getW()){
			//Point_t *dot = new Point_t();
			//ground_vertex.push_back(*dot);
			//delete dot;
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

	//~Ground();

protected:
	const Display display;
	//Point_t *dot;
	list<Point_t> ground_vertex;
};


#endif