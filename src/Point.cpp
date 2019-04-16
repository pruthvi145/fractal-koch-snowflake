#include "Point.h"

Point::Point(){}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point::print()
{
  std::cout<<"x: "<<this->x<<std::endl;
  std::cout<<"y: "<<this->y<<std::endl;
  std::cout<<std::endl;
}

Point Point:: operator+(Point a)
{
    Point res;
    res.x = this->x + a.x;
    res.y = this->y + a.y;
    return res;
}
Point Point:: operator-(Point a)
{
    Point res;
    res.x = this->x - a.x;
    res.y = this->y - a.y;
    return res;
}

Point Point::operator/(int d)
{
    Point res;
    res.x = this->x/d;
    res.y = this->y/d;
    return res;
}

void Point::rotate(float angle)
{
    float r = sqrt(pow(this->x,2)+pow(this->y,2));
    this->x = r*cos(angle);
    this->y = r*sin(angle);
}
