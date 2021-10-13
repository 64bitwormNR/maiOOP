#include <iostream>
#include "square.h"
#include "tvector.h"

using namespace std;

int main()
{
	cout << "Comands:" << endl;
	cout << "a - add new square (a [side_len])" << endl;
	cout << "d - erase square by index (d [idx])" << endl;
	cout << "s - set square by index (s [idx] [side_len])" << endl;
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
				int sl;
				cin >> sl;
				vect->push_back(shared_ptr<Square>(new Square(sl)));
				break;
			}
			case 'd':
			{
				int di;
				cin >> di;
				vect->erase(di);
				break;
			}
			case 's':
			{
				int si,sl;
				cin >> si >> sl;
				shared_ptr<TVectorItem> it(new TVectorItem(shared_ptr<Square>(new Square(sl))));
				(*vect)[si] = it;
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

