#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "figure.h"

class Rectangle: public Figure
{
	public:
		Rectangle(std::istream &is);
		Rectangle(Point pnt1, Point pnt2, Point pnt3, Point pnt4);
		
		size_t VertexesNumber();
		double Area();
		void Print(std::ostream& os);
		
	friend std::istream& operator>>(std::istream& is, Rectangle& p);
	friend std::ostream& operator<<(std::ostream& os, Rectangle& p);

	private:
		Point p1;
		Point p2;
		Point p3;
		Point p4;
};

#endif
