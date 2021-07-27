#ifndef __SHAPE__FILE__
#define __SHAPE__FILE__

#include "Point.h"

#include <string>
#include <vector>

class Shape
{
protected:
	double area;
	bool isCircular;
	Point leftTop;
	double perimeter;
	std::vector<Point> points;

public:
	Shape(double area = 0.0, bool isCircular = false, Point leftTop = Point(-1, -1), double perimeter = 0.0, std::vector<Point> points = std::vector<Point>())
		: area(area), isCircular(isCircular), leftTop(leftTop), perimeter(perimeter), points(points)
	{

	}

	virtual double calculateArea() const = 0;
	virtual double calculatePerimeter() const = 0;
	virtual std::vector<Point> calculatePoints() const = 0;
	virtual std::string toString() const = 0;
};

#endif
