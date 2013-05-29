#include "Header.h"


Point::Point(int x, int y)
{
	Point::x = x;
	Point::y = y;
}


Point::~Point(void)
{
	//Don't know what to write here, maybe that?
	free(&x);
	free(&y);
}
