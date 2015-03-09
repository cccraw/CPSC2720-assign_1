#include "Simulate.h"
#include "Display.h"


void main() {
	srand(time(NULL));

	Display disp; //create a 800x600 window
	Simulate start(disp, 40);
	start.run();
}