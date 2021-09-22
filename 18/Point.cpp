
#include "Point.hpp"


Point::Point(int x1, int y1, int z1)
{
    x = x1;
    y = y1;
    z = z1;
}

Point & Point::operator = (const Point & b)
{
    if (this != &b)
    {
        x = b.x;
        y = b.y;
        z = b.z;
    }
    return (*this);
}

bool operator ==(const Point & a, const Point &b)
{
   return (a.x == b.x && a.y == b.y && a.z == b.z);
   
}

bool operator <(const Point & a, const Point &b){
   return(a.x < b.x && a.y < b.y && a.z < b.z);
}



Point Point::operator + (const Point & b)
{
    Point a = *this;

    a.x = x + b.x;
    a.y = y + b.y;
    a.z = z + b.z;

    return (a);
}

std::ostream& operator << (std::ostream& os, const Point & b)
{
   os<<"("<< b.x << ";" << b.y << ";" << b.z <<")";
return os;
}

