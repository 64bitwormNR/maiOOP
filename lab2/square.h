//SQUARE.H
#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "figure.h"

class Square: public Figure
{
	public:
		Square();
		Square(std::istream &is);
		Square(Point pnt1, Point pnt2, Point pnt3, Point pnt4);

		size_t VertexesNumber();
		double Area();
		void Print(std::ostream& os);
		void Read(std::istream& is);

		Square& operator=(const Square& sq);
		bool operator==(const Square& sq);

	friend std::istream& operator>>(std::istream& is, Square& r);
	friend std::ostream& operator<<(std::ostream& os, Square& r);

	private:
		Point p1;
		Point p2;
		Point p3;
		Point p4;
};

#endif
