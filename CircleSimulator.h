#ifndef __CIRCLESIMULATOR_H
#define __CIRCLESIMULATOR_H

#include "Simulator.h"
#include "Vector.h"
#include "WrapAround.h"
#include <allegro5/allegro_primitives.h>

class CircleSimulator : public Simulator {
private:
	Point origin; // the origin of the Circle
	Vector crtSpeed; // speed in pixels per sec
	int width, height; // of the window
	float radius; // of the circle

public:
	CircleSimulator(const Display & d, int fps, int sq) : Simulator(d, fps),
		origin(200, 300), crtSpeed(300, 600), radius(sq)	{
		width = d.getW(); height = d.getH();
	}

	// side wall loop logic, both x and y (both ways!)
	void updateModel(double dt) {
		Point newOrigin = origin + crtSpeed*dt;
		if (newOrigin.x > width + radius) {
			newOrigin.x = newOrigin.x - width - 2 * radius;
		}

		if (newOrigin.x < 0 - radius){
			newOrigin.x = newOrigin.x + width + 2 * radius;
		}

		if (newOrigin.y > height + radius){
			newOrigin.y = newOrigin.y - height - 2 * radius;
		}

		if (newOrigin.y < 0 - radius) {
			newOrigin.y = newOrigin.y + height + 2 * radius;
		}

		//WrapAround edge(radius, newOrigin);
		//edge.wrap();

		origin = newOrigin;
	}

	void drawModel() {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_circle(
			static_cast<int>(origin.x),
			static_cast<int>(origin.y),
			radius,
			al_map_rgb(200, 200, 0),
			2);
		al_flip_display();
	}
};

#endif
