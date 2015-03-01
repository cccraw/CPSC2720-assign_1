#ifndef __EMPTYSIMULATOR_H
#define __EMPTYSIMULATOR_H

#include "Simulator.h"
#include <iostream>

class EmptySimulator: public Simulator{
private:
	double savedDt; // keep track of the passed dt value
	int nrOfUpdatesSinceDraw; 
public:
EmptySimulator(const Display & d, int fps) : Simulator(d, fps),
		nrOfUpdatesSinceDraw(0), savedDt(0.0) {}

	void updateModel(double dt) {
		savedDt += dt;
		nrOfUpdatesSinceDraw++;
	}

	void drawModel() { std::cout << "Drawing after " << 
			nrOfUpdatesSinceDraw << " updates and " << savedDt << " total sec" <<std::endl;
		nrOfUpdatesSinceDraw = 0;
		savedDt = 0.0;
	};
};

#endif
