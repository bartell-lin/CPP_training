#include "Shape2D.h"
#include <vector>
#include <cmath>

using namespace std;

// Shape2D 
Shape2D::Shape2D() {}
Shape2D::~Shape2D() {}
Shape2D::Shape2D(const Shape2D& other) {}
Shape2D& Shape2D::operator=(const Shape2D& other) {return *this;}
Shape2D::Shape2D(Shape2D&& other) {}
Shape2D& Shape2D::operator=(Shape2D&& other) {return *this;}

double Shape2D::area() {return 0;}
double Shape2D::perimeter() {return 0;}

// Polygon
Polygon::Polygon(vector<vector<int>> lines): lines(lines) {}
Polygon::~Polygon() {}
Polygon::Polygon(const Polygon& other): Shape2D(other) {lines = other.lines;}
Polygon& Polygon::operator=(const Polygon& other) {
	this->Shape2D::operator=(other);
	if (this == &other) return *this;
	lines = other.lines;
	return *this;
}
Polygon::Polygon(Polygon&& other): Shape2D(other) {
	lines = other.lines;
	other.lines.clear();
}
Polygon& Polygon::operator=(Polygon&& other) {
	this->Shape2D::operator=(other);
	if (this == &other) return *this;
	lines = other.lines;
	other.lines.clear();
	return *this;
}

double Polygon::distance(vector<int> p1, vector<int> p2) {
	double x = pow((p1[0] - p2[0]), 2);
	double y = pow((p1[1] - p2[1]), 2);
	return sqrt(x + y);
}

double Polygon::perimeter() {
	double p = distance(lines[0], lines[lines.size() - 1]);
	for (int i = 0; i < lines.size() - 1; i++) {
		p += distance(lines[i], lines[i + 1]);
	}
	return p;
}

// Ellipse
Ellipse::Ellipse(vector<int> center, double r1, double r2): center(center), r1(r1), r2(r2) {}
Ellipse::~Ellipse() {}
Ellipse::Ellipse(const Ellipse& other): Shape2D(other) {
	r1 = other.r1;
	r2 = other.r2;
	center = other.center;
}
Ellipse& Ellipse::operator=(const Ellipse& other) {
	this->Shape2D::operator=(other);
	if (this == &other) return *this;
	r1 = other.r1;
	r2 = other.r2;
	center = other.center;
	return *this;
}
Ellipse::Ellipse(Ellipse&& other): Shape2D(other) {
	r1 = other.r1;
	r2 = other.r2;
	center = other.center;
	other.r1 = 0;
	other.r2 = 0;
	other.center.clear();
}
Ellipse& Ellipse::operator=(Ellipse&& other) {
	this->Shape2D::operator=(other);
	if (this == &other) return *this;
	r1 = other.r1;
	r2 = other.r2;
	center = other.center;
	other.r1 = 0;
	other.r2 = 0;
	other.center.clear();
	return *this;
}
double Ellipse::area() { return 3.14 * r1 * r2;}
double Ellipse::perimeter() {return 3.14 * (r1 + r2);}

// Circle
Circle::Circle(vector<int> center, double r): Ellipse(center, r, r) {};
Circle::~Circle() {}

Circle::Circle(const Circle& other): Ellipse(other) {}
Circle& Circle::operator=(const Circle& other) {
	this->Ellipse::operator=(other);
	return *this;
}
Circle::Circle(Circle&& other): Ellipse(other) {}
Circle& Circle::operator=(Circle&& other) {
	this->Ellipse::operator=(other);
	return *this;
}
double Circle::diameter() {return r1 * 2;}


// Triangle
Triangle::Triangle(double height, double width, vector<vector<int>> lines): height(height), width(width), Polygon(lines) {}
Triangle::~Triangle() {}

Triangle::Triangle(const Triangle& other): Polygon(other) {
	height = other.height;
	width = other.width;
}
Triangle& Triangle::operator=(const Triangle& other) {
	this->Polygon::operator=(other);
	if (this == &other) return *this;
	height = other.height;
	width = other.width;
	return *this;
}
Triangle::Triangle(Triangle&& other): Polygon(other) {
	height = other.height;
	width = other.width;
	other.height = 0;
	other.width = 0;
}
Triangle& Triangle::operator=(Triangle&& other) {
	this->Polygon::operator=(other);
	if (this == &other) return *this;
	height = other.height;
	width = other.width;
	other.height = 0;
	other.width = 0;
	return *this;
}
double Triangle::area() {return .5 * height * width;}


//Quadrilateral
Quadrilateral::Quadrilateral(double height, double width, vector<vector<int>> lines): height(height), width(width), Polygon(lines) {}
Quadrilateral::~Quadrilateral() {}

Quadrilateral::Quadrilateral(const Quadrilateral& other): Polygon(other) {
	height = other.height;
	width = other.width;
}
Quadrilateral& Quadrilateral::operator=(const Quadrilateral& other) {
	this->Polygon::operator=(other);
	if (this == &other) return *this;
	height = other.height;
	width = other.width;
	return *this;
}
Quadrilateral::Quadrilateral(Quadrilateral&& other): Polygon(other) {
	height = other.height;
	width = other.width;
	other.height = 0;
	other.width = 0;
}
Quadrilateral& Quadrilateral::operator=(Quadrilateral&& other) {
	this->Polygon::operator=(other);
	if (this == &other) return *this;
	height = other.height;
	width = other.width;
	other.height = 0;
	other.width = 0;
	return *this;
}



//Trapeziod
Trapeziod::Trapeziod(double height, double width, double width2, vector<vector<int>> lines): width2(width2), Quadrilateral(height, width, lines) {}
Trapeziod::~Trapeziod() {}

Trapeziod::Trapeziod(const Trapeziod& other): Quadrilateral(other) {
	width2 = other.width2;
}
Trapeziod& Trapeziod::operator=(const Trapeziod& other) {
	this->Quadrilateral::operator=(other);
	if (this == &other) return *this;
	width2 = other.width2;
	return *this;
}
Trapeziod::Trapeziod(Trapeziod&& other): Quadrilateral(other) {
	width2 = other.width2;
	other.width2 = 0;
}
Trapeziod& Trapeziod::operator=(Trapeziod&& other) {
	this->Quadrilateral::operator=(other);
	if (this == &other) return *this;
	width2 = other.width2;
	other.width2 = 0;
	return *this;
}

double Trapeziod::area() {return (width + width2) * .5 * height;}


// Parallelogram
Parallelogram::Parallelogram(double height, double width, vector<vector<int>> lines): Quadrilateral(height, width, lines) {}
Parallelogram::~Parallelogram() {}

Parallelogram::Parallelogram(const Parallelogram& other): Quadrilateral(other) {}
Parallelogram& Parallelogram::operator=(const Parallelogram& other) {
	this->Quadrilateral::operator=(other);
	return *this;
}
Parallelogram::Parallelogram(Parallelogram&& other): Quadrilateral(other) {}
Parallelogram& Parallelogram::operator=(Parallelogram&& other) {
	this->Quadrilateral::operator=(other);
	return *this;
}

double Parallelogram::area() {return height * width;}

// Rhombus
Rhombus::Rhombus(double height, double width, vector<vector<int>> lines): Parallelogram(height, width, lines) {}
Rhombus::~Rhombus() {}

Rhombus::Rhombus(const Rhombus& other): Parallelogram(other) {}
Rhombus& Rhombus::operator=(const Rhombus& other) {
	this->Parallelogram::operator=(other);
	return *this;
}
Rhombus::Rhombus(Rhombus&& other): Parallelogram(other) {}
Rhombus& Rhombus::operator=(Rhombus&& other) {
	this->Parallelogram::operator=(other);
	return *this;
}

double Rhombus::area() {return distance(lines[0], lines[2]) * distance(lines[1], lines[4]) * .5;}


// Rectangle
Rectangle::Rectangle(double height, double width, vector<vector<int>> lines): Parallelogram(height, width, lines) {}
Rectangle::~Rectangle() {}

Rectangle::Rectangle(const Rectangle& other): Parallelogram(other) {}
Rectangle& Rectangle::operator=(const Rectangle& other) {
	this->Parallelogram::operator=(other);
	return *this;
}
Rectangle::Rectangle(Rectangle&& other): Parallelogram(other) {}
Rectangle& Rectangle::operator=(Rectangle&& other) {
	this->Parallelogram::operator=(other);
	return *this;
}

// Square
Square::Square(double height, vector<vector<int>> lines): Rectangle(height, height, lines) {} 
Square::~Square() {}

Square::Square(const Square& other): Rectangle(other) {}
Square& Square::operator=(const Square& other) {
	this->Rectangle::operator=(other);
	return *this;
}
Square::Square(Square&& other): Rectangle(other) {}
Square& Square::operator=(Square&& other) {
	this->Rectangle::operator=(other);
	return *this;
}