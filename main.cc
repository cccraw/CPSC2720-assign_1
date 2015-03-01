#include "Display.h"
#include "SquareSimulator.h"


int main(void) {
	Display disp;  // create a 800x600 window
	SquareSimulator simul(disp, 30, 100);  // 2nd arg = fps, 3rd arg = size

	simul.run();
}
