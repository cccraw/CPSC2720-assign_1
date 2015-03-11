/*
Vector_t is used for the speed of the object
*/

#ifndef Vector_t_H
#define Vector_t_H


struct Vector_t {
	double x;
	double y;
	Vector_t(double a = 0.0, double b = 0.0) : x(a), y(b) {};

	Vector_t operator * (double scalar) {
		return Vector_t(x*scalar, y*scalar);
	}
	bool operator==(Vector_t p){
		if (x == p.x && y == p.y)
			return true;
		else
			return false;
	}
	Vector_t operator+(Vector_t v) {
		return Vector_t(x + v.x, y + v.y);
	}
	Vector_t operator-(Vector_t v) {
		return Vector_t(x - v.x, y - v.y);
	}
};


struct Point {
	double x;
	double y;
	Point(double a = 0.0, double b = 0.0) : x(a), y(b) {};

	Point operator+(Vector_t v) {
		return Point(x + v.x, y + v.y);
	}

	Point operator-(Vector_t v) {
		return Point(x - v.x, y - v.y);
	}

	bool operator==(Point p){
		if (x == p.x && y == p.y)
			return true;
		else
			return false;
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