#ifndef MOVABLE_H
#define MOVABLE_H

class Movable
{
public:
	Movable();

	~Movable();

	virtual void updateShape(double) = 0;

protected:
};

#endif