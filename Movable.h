#ifndef __MOVEABLE__FILE__
#define __MOVEABLE__FILE__

#include "Point.h"

class Movable
{
public:
	virtual void move(int newX, int newY) = 0;
	virtual void scale(double scaleX, double scaleY) = 0;
};

#endif
