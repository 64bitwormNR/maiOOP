//TRAPEZOID.H
#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <iostream>
#include "figure.h"

class Trapezoid: public Figure
{
	public:
		Trapezoid(std::istream &is);
		Trapezoid(Point p1, Point p2, Point p3, Point p4);

		size_t VertexesNumber();
		double Area();
		void Print(std::ostream& os);
		void Read(std::istream& is);

		Trapezoid& operator=(const Trapezoid& sq);
		bool operator==(const Trapezoid& sq);

	friend std::istream& operator>>(std::istream& is, Trapezoid& r);
	friend std::ostream& operator<<(std::ostream& os, Trapezoid& r);

	private:
		Point p1;
		Point p2;
		Point p3;
		Point p4;
};

#endif
