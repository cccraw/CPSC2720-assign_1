#ifndef SIMULATE_H
#define SIMULATE_H

#include "Display.h"
#include "Ground.h"
#include "Square.h"
#include "Circle.h"
#include "Drawable.h"
#include "Movable.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <cstdlib>
#include <list>
#include <memory>
#include <iterator>

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

		//addGround();
		grPtr = make_shared<Ground>(display);
		shared_ptr<Drawable> groD0 = grPtr;
		drawList.push_back(groD0);

		//create each shape
		for (int i = 0; i < NUMSHAPES; i++) {
			addCircle();
			addSquare();
		}

		//Square sq(display, FPS, sz);
		//Circle c1(display, FPS, sz1);
		//Ground gr(display);
		//shared_ptr<Drawable> gr0(new Ground(display));
		//drawList.push_back(gr0);
		//drawList.push_back(cirD0);
		//moveList.push_back(cirM0);

		while (1) {
			ALLEGRO_EVENT ev;
			al_wait_for_event(eventQueue, &ev);



			if (ev.type == ALLEGRO_EVENT_TIMER) {
				crtTime = al_current_time();
				for (list<shared_ptr<Movable>>::iterator it = moveList.begin(); it != moveList.end(); it++) {
					(*it)->updateShape(crtTime - prevTime);
				}
				prevTime = crtTime;
				redraw = true;
			}
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				break;
			}

			if (redraw && al_is_event_queue_empty(eventQueue)) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				for (list<shared_ptr<Drawable>>::iterator it = drawList.begin(); it != drawList.end(); it++) {
					(*it)->drawShape();
				}


				al_flip_display();

				redraw = false;
			}
		}
	}

	void addCircle(){
		int sz = rand() % 100;

		shared_ptr<Circle> tempCircle = make_shared<Circle>(display, FPS, sz, grPtr);
		shared_ptr<Drawable> cirD0 = tempCircle;
		shared_ptr<Movable> cirM0 = tempCircle;
		drawList.push_back(cirD0);
		moveList.push_back(cirM0);
	}
	void addSquare(){
		int sz = rand() % 100;

		shared_ptr<Square> tempSquare = make_shared<Square>(display, FPS, sz, grPtr);
		shared_ptr<Drawable> squD0 = tempSquare;
		shared_ptr<Movable> squM0 = tempSquare;
		drawList.push_back(squD0);
		moveList.push_back(squM0);
	}
	//void addGround(){
	//	shared_ptr<Ground> tempGround = make_shared<Ground>(display);
	//	shared_ptr<Drawable> groD0 = tempGround;
	//	drawList.push_back(groD0);
	//}
private:

	int FPS;
	ALLEGRO_EVENT_QUEUE *eventQueue;
	ALLEGRO_TIMER *timer;
	const Display display;
	list<shared_ptr<Drawable>> drawList;
	list<shared_ptr<Movable>> moveList;
	const int NUMSHAPES = 2;
	shared_ptr<Ground> grPtr;
};

#endif