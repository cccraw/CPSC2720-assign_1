#ifndef __SQUARESIMULATOR_H
#define __SQUARESIMULATOR_H

#include "Simulator.h"
#include <allegro5/allegro_primitives.h>

struct Vector {
	double x;
	double y;
	Vector (double a=0.0, double b=0.0) : x(a), y(b) {};

	Vector operator * (double scalar) {
		return Vector(x*scalar, y*scalar);
	}

	Vector reflectOverXAxis() {
		return Vector(x, -y);
	}

	Vector reflectOverYAxis() {
		return Vector(-x, y);
	}

	Vector wrapXAxis(int w, int h) {
		return Vector(x, y);
	}

	Vector wrapYAxis(int w, int h) {
		return Vector(x, y);
	}
};


struct Point {
	double x;
	double y;
Point(double a=0.0, double b=0.0): x(a), y(b) {};
	Point operator + (Vector v) {
		return Point(x+v.x, y+v.y);
	}
};


	
class SquareSimulator: public Simulator {
private:
	Point origin; // the origin of the square
	Vector crtSpeed; // speed in pixels per sec
	int width, height; // of the window
	int squareSize; // of the drawn block in pixels

public:
SquareSimulator(const Display & d, int fps, int sq) : Simulator(d, fps),
		origin(400, 300), crtSpeed(300, 300), squareSize(sq)
	{ width = d.getW(); height = d.getH(); }

	// outside wall collision logic goes here
	//void updateModel(double dt) {
	//	Point newOrigin = origin + crtSpeed*dt;
	//	if (newOrigin.x < 0 || newOrigin.x > width-squareSize) {
	//		crtSpeed = crtSpeed.reflectOverYAxis();
	//		if (newOrigin.x < 0) {
	//			newOrigin.x = -newOrigin.x;  // ugly reflection
	//		} else {
	//			newOrigin.x = 2*width -2*squareSize - newOrigin.x; // also ugly
	//		}			
	//	}

	//	if (newOrigin.y < 0 || newOrigin.y > height-squareSize) {
	//		crtSpeed = crtSpeed.reflectOverXAxis();
	//		if (newOrigin.y < 0) {
	//			newOrigin.y = -newOrigin.y;
	//		}
	//		else {
	//			newOrigin.y = 2*height -2*squareSize - newOrigin.y;
	//		}
	//	}
	//	origin = newOrigin;
	//}
void updateModel(double dt) {
	Point newOrigin = origin + crtSpeed*dt;
	if (newOrigin.x > width + squareSize) {
// 		crtSpeed = crtSpeed.wrapYAxis(width, height);
// 		if (newOrigin.x < 0) {
// 			newOrigin.x = -newOrigin.x;  // ugly reflection
// 		}
// 		else {
// 			newOrigin.x = 2 * width - 2 * squareSize - newOrigin.x; // also ugly
// 		}
		newOrigin.x = newOrigin.x - width - 2*squareSize;
	}

	if (newOrigin.y < 0 || newOrigin.y > height - squareSize) {
		crtSpeed = crtSpeed.reflectOverXAxis();
		if (newOrigin.y < 0) {
			newOrigin.y = -newOrigin.y;
		}
		else {
			newOrigin.y = 2 * height - 2 * squareSize - newOrigin.y;
		}
	}
	origin = newOrigin;
}

	void drawModel() {
		al_clear_to_color(al_map_rgb(0,0,0));
		al_draw_rectangle(static_cast<int>(origin.x),
											static_cast<int>(origin.y),
											static_cast<int>(origin.x)+squareSize,
											static_cast<int>(origin.y)+squareSize,
											al_map_rgb(200, 200, 0),
											2);
		al_flip_display();
	}
};

#endif
