#ifndef __RECTANGLE__FILE__
#define __RECTANGLE__FILE__

#include "Shape.h"
#include "Movable.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

class Rectangle : public Shape, public Movable
{
	int width;
	int height;

public:
	Rectangle(int x, int y, int width, int height)
		: Shape(width* height, false, Point(x, y), 2 * (width + height)), width(width), height(height)
	{
		area = width * height;
		perimeter = 2 * (width + height);
		points.emplace_back(Point(x, y));
		points.emplace_back(Point(x + width, y));
		points.emplace_back(Point(x + width, y + height));
		points.emplace_back(Point(x, y + height));
	}

	virtual double calculateArea() const
	{
		return width * height;
	}

	virtual double calculatePerimeter() const
	{
		return 2 * (width + height);
	}

	virtual std::vector<Point> calculatePoints() const
	{
		return points;
	}

	virtual std::string toString() const
	{
		std::stringstream ss;
		ss << "Rectange[h=" << height << ",w=" << width << "]\n";
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
		points.emplace_back(Point(newX + width, newY));
		points.emplace_back(Point(newX + width, newY + height));
		points.emplace_back(Point(newX, newY + height));
	}

	virtual void scale(double scaleX, double scaleY)
	{
		width *= scaleX;
		height *= scaleY;

		points.clear();

		points.emplace_back(Point(leftTop.get_x(), leftTop.get_y()));
		points.emplace_back(Point(leftTop.get_x() + width, leftTop.get_y()));
		points.emplace_back(Point(leftTop.get_x() + width, leftTop.get_y() + height));
		points.emplace_back(Point(leftTop.get_x(), leftTop.get_y() + height));
	}

	friend std::ostream& operator<<(std::ostream& o, const Rectangle* c)
	{
		o << c->toString();
		return o;
	}
};

#endif
