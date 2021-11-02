#include <iostream>
#include "square.h"
#include "tvector.h"

using namespace std;

int main()
{
	cout << "Comands:" << endl;
	cout << "a - add new square (a [input])" << endl;
	cout << "d - erase square by index (d [idx])" << endl;
	cout << "s - set square by index (s [idx] [input])" << endl;
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
				vect->InsertLast(shared_ptr<Figure>(new Square(cin)));
				break;
			}
			case 'd':
			{
				int di;
				cin >> di;
				vect->Erase(di);
				break;
			}
			case 's':
			{
				int si;
				cin >> si;
				(*vect)[si] = shared_ptr<Figure>(new Square(cin));
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

