#ifndef SIMULATE_H
#define SIMULATE_H

#include "Display.h"
#include "Ground.h"
#include "Square.h"
#include "Circle.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <cstdlib>
#include <list>

class Simulate {
public:
	Simulate(const Display &d, int fps) :
		display(d), FPS(fps), timer(NULL), eventQueue(NULL) {

		if ((timer = al_create_timer(1.0 / fps)) == NULL)
			throw std::runtime_error("Cannot create allegro timer");
		if ((eventQueue = al_create_event_queue()) == NULL)
			throw std::runtime_error("Cannot create event queue");

		al_register_event_source(eventQueue, al_get_display_event_source(d.getAllegroDisplay()));

		al_register_event_source(eventQueue, al_get_timer_event_source(timer));

		al_start_timer(timer);

	}

	Simulate::~Simulate() {
		if (timer != NULL)
			al_destroy_timer(timer);
		if (eventQueue != NULL)
			al_destroy_event_queue(eventQueue);
	}

	void run() {
		bool redraw = true;
		double crtTime, prevTime = 0;


		//create each shape

		Square sq(display, FPS, sz);
		Circle c1(display, FPS, sz1);
		Ground gr(display);

		while (1) {
			ALLEGRO_EVENT ev;
			al_wait_for_event(eventQueue, &ev);



			if (ev.type == ALLEGRO_EVENT_TIMER) {
				crtTime = al_current_time();
				sq.updateShape(crtTime - prevTime);
				c1.updateShape(crtTime - prevTime);
				prevTime = crtTime;
				redraw = true;
			}
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				break;
			}

			if (redraw && al_is_event_queue_empty(eventQueue)) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				gr.drawShape();
				sq.drawShape();
				c1.drawShape();
			
				al_flip_display();

				redraw = false;
			}
		}
	}

private:

	int FPS;
	ALLEGRO_EVENT_QUEUE *eventQueue;
	ALLEGRO_TIMER *timer;
	const Display display;
	enum shapes { Squ, Cir, last };
	int sz = rand() % 100;
	int sz1 = rand() % 100;

};

#endif