#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include "point.h"

class Figure
{
	public:
		virtual size_t VertexesNumber() = 0;
		virtual double Area() = 0;
		virtual void Print(std::ostream& os) = 0;
		double calcTriangleArea(Point p1, Point p2, Point p3);
		virtual ~Figure() {}
		
		friend std::ostream& operator<<(std::ostream& os, Figure& p)
		{
			p.Print(os); 
			return os;
		}
};

#endif // FIGURE_H
