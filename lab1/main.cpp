#include <iostream>
#include "point.h"
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

using namespace std;

int main(int argc,char *argv[])
{
  cout<<"Variant 2:"<<endl;
  cout<<"Enter rectangle coords (for example: 0 0 5 0 5 5 0 5)"<<endl;
  Figure* fig = new Rectangle(cin);
  fig->Print(cout);
  cout<<"Vertices: "<<(fig->VertexesNumber())<<endl;
  cout<<"Area: "<<(fig->Area())<<endl;
  delete fig;
  cout<<"Enter square coords (for example: 0 0 5 0 5 5 0 5)"<<endl;
  fig = new Square(cin);
  fig->Print(cout);
  cout<<"Vertices: "<<(fig->VertexesNumber())<<endl;
  cout<<"Area: "<<(fig->Area())<<endl;
  delete fig;
  cout<<"Enter trapezoid coords (for example: 1 1 2 2 3 3 4 4)"<<endl;
  fig = new Trapezoid(cin);
  fig->Print(cout);
  cout<<"Vertices: "<<(fig->VertexesNumber())<<endl;
  cout<<"Area: "<<(fig->Area())<<endl;
  delete fig;
  return 0;
}

