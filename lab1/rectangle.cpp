#include "rectangle.h"

#include <cmath>

Rectangle::Rectangle(std::istream &is)
{
	is >> *this;
}

Rectangle::Rectangle(Point pnt1, Point pnt2, Point pnt3, Point pnt4)
{
	p1 = pnt1;
	p2 = pnt2;
	p3 = pnt3;
	p4 = pnt4;
}

size_t Rectangle::VertexesNumber()
{
	return 4;
}

double Rectangle::Area()
{
	return calcTriangleArea(p1,p2,p3)+calcTriangleArea(p3,p4,p1);
}

void Rectangle::Print(std::ostream& os)
{
	os << *this;
}

std::istream& operator>>(std::istream& is, Rectangle& r) {
  is >> r.p1 >> r.p2 >> r.p3 >> r.p4;
  return is;
}

std::ostream& operator<<(std::ostream& os, Rectangle& r) {
  os << "Rectangle: " << r.p1 << " " << r.p2 << " " << r.p3 << " " << r.p4 << "\n";
  return os;
}

