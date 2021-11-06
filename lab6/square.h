//SQUARE.H
#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "figure.h"
#include "tallocator.h"

class Square: public Figure
{
	public:
		Square();
		~Square();
		Square(std::istream &is);
		Square(Point pnt1, Point pnt2, Point pnt3, Point pnt4);

		size_t VertexesNumber();
		double Area();
		void Print(std::ostream& os);
		void Read(std::istream& is);

		Square& operator=(const Square& sq);
		bool operator==(const Square& sq);
		void* operator new(size_t size);
		void operator delete(void* ptr);

	friend std::istream& operator>>(std::istream& is, Square& r);
	friend std::ostream& operator<<(std::ostream& os, Square& r);

	private:
		Point p1;
		Point p2;
		Point p3;
		Point p4;
		static TAllocator talloc;
};

#endif
