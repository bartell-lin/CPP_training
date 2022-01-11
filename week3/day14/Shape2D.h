#include <vector>
#include <string>
using namespace std;

class Shape2D {
public:
	Shape2D() = default;
	virtual ~Shape2D() = default;

	Shape2D(const Shape2D& other) = default;
	Shape2D& operator=(const Shape2D& other) = default;
	Shape2D(Shape2D&& other) = default;
	Shape2D& operator=(Shape2D&& other) = default;

	inline static string called;

	virtual double area() = 0;
	virtual double perimeter() = 0;
};

class Polygon: public Shape2D {
protected:
	vector<vector<int>> lines;
public:
	Polygon(vector<vector<int>> lines);
	~Polygon();

	Polygon(const Polygon& other);
	Polygon& operator=(const Polygon& other);
	Polygon(Polygon&& other);
	Polygon& operator=(Polygon&& other);

	double distance(vector<int> p1, vector<int> p2);
	double perimeter();

};

class Ellipse: public Shape2D {
protected:
	double r1;
	double r2;
	vector<int> center;
public:
	Ellipse(vector<int> center, double r1, double r2);
	~Ellipse();

	Ellipse(const Ellipse& other);
	Ellipse& operator=(const Ellipse& other);
	Ellipse(Ellipse&& other);
	Ellipse& operator=(Ellipse&& other);

	double area();
	double perimeter();


};

class Circle: public Ellipse {
public:
	Circle(vector<int> center, double r);
	~Circle();

	Circle(const Circle& other);
	Circle& operator=(const Circle& other);
	Circle(Circle&& other);
	Circle& operator=(Circle&& other);

	double diameter();
};

class Triangle: public Polygon {
protected:
	double height;
	double width;
public:
	Triangle(double height, double width, vector<vector<int>> lines);
	~Triangle();

	Triangle(const Triangle& other);
	Triangle& operator=(const Triangle& other);
	Triangle(Triangle&& other);
	Triangle& operator=(Triangle&& other);

	virtual double area();
};


class Quadrilateral: public Polygon {
protected:
	double height;
	double width;
public:
	Quadrilateral(double height, double width, vector<vector<int>> lines);
	~Quadrilateral();

	Quadrilateral(const Quadrilateral& other);
	Quadrilateral& operator=(const Quadrilateral& other);
	Quadrilateral(Quadrilateral&& other);
	Quadrilateral& operator=(Quadrilateral&& other);

};

class Trapeziod: public Quadrilateral {
protected:
	double width2;
public:
	Trapeziod(double height, double width, double width2, vector<vector<int>> lines);
	~Trapeziod();

	Trapeziod(const Trapeziod& other);
	Trapeziod& operator=(const Trapeziod& other);
	Trapeziod(Trapeziod&& other);
	Trapeziod& operator=(Trapeziod&& other);
	virtual double area();
};

class Parallelogram: public Quadrilateral {
public:
	Parallelogram(double height, double width, vector<vector<int>> lines);
	~Parallelogram();

	Parallelogram(const Parallelogram& other);
	Parallelogram& operator=(const Parallelogram& other);
	Parallelogram(Parallelogram&& other);
	Parallelogram& operator=(Parallelogram&& other);

	virtual double area();
};

class Rhombus: public Parallelogram {
public:
	Rhombus(double height, double width, vector<vector<int>> lines);
	~Rhombus();

	Rhombus(const Rhombus& other);
	Rhombus& operator=(const Rhombus& other);
	Rhombus(Rhombus&& other);
	Rhombus& operator=(Rhombus&& other);

	virtual double area();
};

class Rectangle: public Parallelogram {
public:
	Rectangle(double height, double width, vector<vector<int>> lines);
	~Rectangle();

	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	Rectangle(Rectangle&& other);
	Rectangle& operator=(Rectangle&& other);
};

class Square: public Rectangle {
public:
	Square(double height, vector<vector<int>> lines);
	~Square();

	Square(const Square& other);
	Square& operator=(const Square& other);
	Square(Square&& other);
	Square& operator=(Square&& other);
};