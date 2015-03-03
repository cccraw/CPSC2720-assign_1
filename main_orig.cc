#include "Display.h"
#include "SquareSimulator.h"
#include "CircleSimulator.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main(void) {
	Display disp;  // create a 800x600 window
	SquareSimulator simsq(disp, 30, 100);  // 2nd arg = fps, 3rd arg = size
	CircleSimulator simcir(disp, 60, 50);

	simsq.run();

	//ALLEGRO_EVENT_QUEUE *eventQueue = NULL;  /// event storage 
	//bool redraw = true;
	//// current time and previous time in seconds; needed so we can try
	//// to keep track of the passing of real time.
	//double crtTime, prevTime = 0;

	//while (1) {
	//	ALLEGRO_EVENT ev;
	//	al_wait_for_event(eventQueue, &ev);

	//	if (ev.type == ALLEGRO_EVENT_TIMER) {
	//		crtTime = al_current_time();
	//		simsq.updateModel(crtTime - prevTime);
	//		simcir.updateModel(crtTime - prevTime);
	//		prevTime = crtTime;
	//		// instead of simply calling drawModel() here, we set this flag so that
	//		// we redraw only if the event queue is empty; reason: draw is expensive and
	//		// we don't want to delay everything too much
	//		redraw = true;
	//	}
	//	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
	//		break;
	//	}

	//	if (redraw && al_is_event_queue_empty(eventQueue)) {
	//		simsq.drawModel();
	//		simcir.drawModel();
	//		redraw = false;
	//	}
	//}




}
