#ifndef __SQUARESIMULATOR_H
#define __SQUARESIMULATOR_H

#include "Simulator.h"
#include "Vector.h"
#include <allegro5/allegro_primitives.h>



class SquareSimulator : public Simulator {
private:
	Point origin; // the origin of the square
	Vector crtSpeed; // speed in pixels per sec
	int width, height; // of the window
	int squareSize; // of the drawn block in pixels

public:
	SquareSimulator(const Display & d, int fps, int sq) : Simulator(d, fps),
		origin(400, 300), crtSpeed(300, 600), squareSize(sq)	{
		width = d.getW(); height = d.getH();
	}

	// side wall loop logic, both x and y (both ways!)
	void updateModel(double dt) {
		Point newOrigin = origin + crtSpeed*dt;
		if (newOrigin.x > width + squareSize) {
			newOrigin.x = newOrigin.x - width - 2 * squareSize;
		}

		if (newOrigin.x < 0 - squareSize){
			newOrigin.x = newOrigin.x + width + 2 * squareSize;
		}

		if (newOrigin.y > height + squareSize){
			newOrigin.y = newOrigin.y - height - 2 * squareSize;
		}

		if (newOrigin.y < 0 - squareSize) {
			newOrigin.y = newOrigin.y + height + 2 * squareSize;
		}

		origin = newOrigin;
	}

	void drawModel() {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_rectangle(static_cast<int>(origin.x),
			static_cast<int>(origin.y),
			static_cast<int>(origin.x) + squareSize,
			static_cast<int>(origin.y) + squareSize,
			al_map_rgb(200, 200, 0),
			2);
		al_flip_display();
	}
};

#endif
