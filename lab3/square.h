#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

class Square
{
	public:
		Square(std::istream &is);
		Square(int sideLen);
		Square();
		~Square();
		
		size_t VertexesNumber();
		double Area();
		void Print(std::ostream& os);
		
	Square& operator=(const Square& sq);
	bool operator==(const Square& sq);
	
	friend std::istream& operator>>(std::istream& is, Square& r);
	friend std::ostream& operator<<(std::ostream& os, Square& r);

	private:
		int side_len;
};

#endif
