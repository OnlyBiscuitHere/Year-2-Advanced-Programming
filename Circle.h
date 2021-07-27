#ifndef __CIRCLE__FILE__
#define __CIRCLE__FILE__

#include "Shape.h"
#include "Movable.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

#define PI 3.141592

class Circle : public Shape, public Movable
{
	double radius;

public:
	Circle(int x, int y, int radius)
		: Shape(0.0, true, Point(x, y), 0.0), radius(radius)
	{
		area = PI * radius * radius;
		perimeter = 2.0 * PI * radius;
		points.push_back(leftTop);
		points.emplace_back(Point(x + (2 * radius), y + (2 * radius)));
	}

	virtual double calculateArea() const
	{
		return PI * radius * radius;
	}

	virtual double calculatePerimeter() const
	{
		return 2.0 * PI * radius;
	}

	virtual std::vector<Point> calculatePoints() const
	{
		return points;
	}

	virtual std::string toString() const
	{
		std::stringstream ss;
		ss << "Circle[r=" << radius << "]\n";
		ss << "Points[";
		for (const Point& p : points)
		{
			ss << "(" << std::fixed << std::setprecision(1) << p.get_x() << "," << std::fixed << std::setprecision(1) << p.get_y() << ")";
		}
		ss << "]\n";
		ss << "Area=" << calculateArea() << " Perimeter=" << calculatePerimeter() << "\n";

		return ss.str();
	}

	virtual void move(int newX, int newY)
	{
		points.clear();
		leftTop.set_x(newX);
		leftTop.set_y(newY);
		points.emplace_back(Point(newX, newY));
		points.emplace_back(Point(newX + (2 * radius), newY + (2 * radius)));
	}

	virtual void scale(double scaleX, double scaleY)
	{
		if (scaleX != scaleY)
		{
			throw std::runtime_error("In Circle::scale(), scaleX != scaleY");
		}

		radius *= scaleY;
		points.pop_back();
		points.emplace_back(Point(points[0].get_x() + (2 * radius), points[0].get_y() + (2 * radius)));
	}

	friend std::ostream& operator<<(std::ostream& o, const Circle* c)
	{
		o << c->toString();
		return o;
	}
};

#endif
