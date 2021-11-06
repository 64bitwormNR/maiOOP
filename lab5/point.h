//POINT.H
#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
public:
  Point();
  Point(std::istream &is);
  Point(double x, double y);

  double x_;
  double y_;

  double dist(Point& other);

  Point& operator=(const Point& sq);
  bool operator==(const Point& sq);

  friend std::istream& operator>>(std::istream& is, Point& p);
  friend std::ostream& operator<<(std::ostream& os, Point& p);
};

#endif // POINT_H
