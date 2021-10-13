#include "square.h"

Square::Square(std::istream &is)
{
	is >> *this;
}

Square::Square(int sideLen)
{
	side_len = sideLen;
	printf("[%d] created\n", side_len);
}

Square::Square()
{
	side_len = 0;
}

size_t Square::VertexesNumber()
{
	return 4;
}

double Square::Area()
{
	return side_len*side_len;
}

void Square::Print(std::ostream& os)
{
	os << *this;
}

Square& Square::operator=(const Square& sq)
{
	side_len=sq.side_len;
	return *this;
}

bool Square::operator==(const Square& sq)
{
	return side_len==sq.side_len;
}

std::istream& operator>>(std::istream& is, Square& r)
{
	is >> r.side_len;
	return is;
}

std::ostream& operator<<(std::ostream& os, Square& r)
{
	os << "Square: " << r.side_len << 'x' << r.side_len;
	return os;
}

Square::~Square()
{
	printf("[%d] destroyed\n", side_len);
}
