//SQUARE.CPP
#include "square.h"

#include <cmath>

Square::Square() {}

Square::Square(std::istream &is)
{
	is >> *this;
}

Square::Square(Point pnt1, Point pnt2, Point pnt3, Point pnt4)
{
	p1 = pnt1;
	p2 = pnt2;
	p3 = pnt3;
	p4 = pnt4;
}

size_t Square::VertexesNumber()
{
	return 4;
}

double Square::Area()
{
	return calcTriangleArea(p1,p2,p3)+calcTriangleArea(p3,p4,p1);
}

void Square::Print(std::ostream& os)
{
	os << *this;
}

void Square::Read(std::istream& is)
{
	is >> *this;
}

Square& Square::operator=(const Square& sq)
{
	p1=sq.p1;
	p2=sq.p2;
	p3=sq.p3;
	p4=sq.p4;
	return *this;
}

bool Square::operator==(const Square& sq)
{
	return p1==sq.p1 && p2==sq.p2 && p3==sq.p3 && p4==sq.p4;
}

std::istream& operator>>(std::istream& is, Square& r) {
  is >> r.p1 >> r.p2 >> r.p3 >> r.p4;
  return is;
}

std::ostream& operator<<(std::ostream& os, Square& r) {
  os << "Square: " << r.p1 << " " << r.p2 << " " << r.p3 << " " << r.p4;
  return os;
}
