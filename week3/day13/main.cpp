#include "Shape2D.h"
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;


int main() {
	vector<int> center = {0, 0};
	Circle c(center, 3);
	Ellipse e = c;
	assert(e.area() == c.area());
	assert(e.perimeter() == c.perimeter());


	vector<vector<int>> v {{0, 0}, {0, 3}, {4, 0}};
	Triangle t(3, 4, v);
	Triangle t2(t);
	assert(t.area() == t2.area());

	vector<vector<int>> v2 {{0, 0}, {0, 3}, {3, 3}, {3, 0}};
	Square s(3, v2);
	Rectangle r = s;
	assert(s.area() == r.area());
	assert(s.perimeter() == r.perimeter());
	Quadrilateral q = move(r);
	assert(r.area() == 0);
}