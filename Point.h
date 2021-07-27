#ifndef __POINT_FILE__
#define __POINT_FILE__

class Point
{
	int x;
	int y;

public:
	Point(int x, int y)
		: x(x), y(y)
	{

	}

	int get_x() const;
	int get_y() const;
	void set_x(int _x);
	void set_y(int _y);
};

#endif
