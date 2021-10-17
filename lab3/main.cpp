//MAIN.CPP
#include <iostream>
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "point.h"
#include "tvector.h"

using namespace std;

int main()
{
	cout << "Comands:" << endl;
	cout << "a - add new figure (a r|s|t [input])" << endl;
	cout << "d - erase square by index (d [idx])" << endl;
	cout << "p - print all containing squares (p)" << endl;
	cout << "q - quit (q)" << endl;
	char running = 1;
	TVector *vect = new TVector();
	char cmd;
	while(running)
	{
		cout << "> ";
		cin >> cmd;
		switch(cmd)
		{
			case 'a':
			{
				char fig;
				cin >> fig;
				switch(fig)
				{
					case 's':
						vect->push_back(shared_ptr<Figure>(new Square(cin)));
						break;
					case 'r':
						vect->push_back(shared_ptr<Figure>(new Rectangle(cin)));
						break;
					case 't':
						vect->push_back(shared_ptr<Figure>(new Trapezoid(cin)));
						break;
				}
				break;
			}
			case 'd':
			{
				int di;
				cin >> di;
				vect->erase(di);
				break;
			}
			case 'p':
			{
				cout << *vect << endl;
				break;
			}
			case 'q':
			{
				running = 0;
				break;
			}
			default:
				cout << "wrong input" << endl;
		}
	}
	delete vect;
}
