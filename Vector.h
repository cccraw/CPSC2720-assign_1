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

ALLEGRO_COLOR getColor(){
	int r, g, b;
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
	return al_map_rgb(r, g, b);

}



#endif