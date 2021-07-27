#ifndef __SQUARE__FILE__
#define __SQUARE__FILE__

#include "Shape.h"
#include "Movable.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

class Square : public Shape, public Movable
{
	int edge_length;

public:
	Square(int x, int y, int e)
		: Shape(e* e, false, Point(x, y), 2 * (e + e)), edge_length(e)
	{
		area = e * e;
		perimeter = 2 * (e + e);
		points.emplace_back(Point(x, y));
		points.emplace_back(Point(x + e, y));
		points.emplace_back(Point(x + e, y + e));
		points.emplace_back(Point(x, y + e));
	}

	virtual double calculateArea() const
	{
		return edge_length * edge_length;
	}

	virtual double calculatePerimeter() const
	{
		return 2 * (edge_length + edge_length);
	}

	virtual std::vector<Point> calculatePoints() const
	{
		return points;
	}

	virtual std::string toString() const
	{
		std::stringstream ss;
		ss << "Square[e=" << edge_length << "]\n";
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
		points.emplace_back(Point(newX + edge_length, newY));
		points.emplace_back(Point(newX + edge_length, newY + edge_length));
		points.emplace_back(Point(newX, newY + edge_length));
	}

	virtual void scale(double scaleX, double scaleY)
	{
		if (scaleX != scaleY)
		{
			throw std::runtime_error("In Square::scale(), scaleX != scaleY");
		}

		edge_length *= scaleY;

		points.clear();

		points.emplace_back(Point(leftTop.get_x(), leftTop.get_y()));
		points.emplace_back(Point(leftTop.get_x() + edge_length, leftTop.get_y()));
		points.emplace_back(Point(leftTop.get_x() + edge_length, leftTop.get_y() + edge_length));
		points.emplace_back(Point(leftTop.get_x(), leftTop.get_y() + edge_length));
	}

	friend std::ostream& operator<<(std::ostream& o, const Square* c)
	{
		o << c->toString();
		return o;
	}
};

#endif
