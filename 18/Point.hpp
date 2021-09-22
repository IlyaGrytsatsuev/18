
#ifndef Point_hpp
#define Point_hpp
#include <cstdio>
#include <iostream>

class Point
 {
 private:
     int x,
         y,
         z;
 public:
     Point(){x=y=z=0;};
     Point (int x1, int y1, int z1);
     Point & operator = (const Point & b);
     Point operator + (const Point & b);
     friend std::ostream& operator << (std::ostream& os, const Point & b);
     friend bool operator <(const Point & a, const Point &b);
     friend bool operator ==(const Point & a, const Point &b);
 };

#endif /* Point_hpp */

