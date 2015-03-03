/*
Vector is used for the speed of the object
*/

#ifndef VECTOR_H
#define VECTOR_H


struct Vector {
	double x;
	double y;
	Vector(double a = 0.0, double b = 0.0) : x(a), y(b) {};

	Vector operator * (double scalar) {
		return Vector(x*scalar, y*scalar);
	}
};


struct Point {
	double x;
	double y;
	Point(double a = 0.0, double b = 0.0) : x(a), y(b) {};
	Point operator + (Vector v) {
		return Point(x + v.x, y + v.y);
	}
};

#endif