#include "trapezoid.h"

#include <cmath>

Trapezoid::Trapezoid(std::istream &is)
{
	is >> *this;
}

Trapezoid::Trapezoid(Point p1, Point p2, Point p3, Point p4)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
}

size_t Trapezoid::VertexesNumber()
{
	return 4;
}

double Trapezoid::Area()
{
	return calcTriangleArea(p1,p2,p3)+calcTriangleArea(p3,p4,p1);
}

void Trapezoid::Print(std::ostream& os)
{
	os << *this;
}

std::istream& operator>>(std::istream& is, Trapezoid& r) {
  is >> r.p1 >> r.p2 >> r.p3 >> r.p4;
  return is;
}

std::ostream& operator<<(std::ostream& os, Trapezoid& r) {
  os << "Trapezoid: " << r.p1 << " " << r.p2 << " " << r.p3 << " " << r.p4 << "\n";
  return os;
}

