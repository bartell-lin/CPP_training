#include "Shape2D.h"
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;


int main() {
	vector<int> center = {0, 0};
	Circle c(center, 3);
	c.area();
	assert(Circle::called == "Ellipse");
	c.perimeter();
	assert(Circle::called == "Ellipse");


	vector<vector<int>> v {{0, 0}, {0, 3}, {4, 0}};
	Triangle t(3, 4, v);
	t.area();
	assert(Triangle::called == "Triangle");
	t.perimeter();
	assert(Triangle::called == "Polygon");


	vector<vector<int>> v2 {{0, 0}, {0, 3}, {3, 3}, {3, 0}};
	Square s(3, v2);
	s.area();
	assert(Square::called == "Parallelogram");
	s.perimeter();
	assert(Square::called == "Polygon");

	Rectangle r = s;
	r.area();
	assert(Rectangle::called == "Parallelogram");
	r.perimeter();
	assert(Rectangle::called == "Polygon");


	vector<vector<int>> v3 {{0, 0}, {1, 3}, {3, 3}, {4, 0}};
	Trapeziod tp(3, 2, 4, v3);
	tp.area();
	assert(Trapeziod::called == "Trapeziod");
	tp.perimeter();
	assert(Trapeziod::called == "Polygon");
	
	cout << "Asserts passed" << endl;
}