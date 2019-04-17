#include "Segment.h"
#define PI 3.1415

Segment::Segment(){} //default Constructor

Segment::Segment(Point a, Point b)
{
    this->a = a;
    this->b = b;
}

void Segment::setpoints(Point a, Point b)
{
    this->a = a;
    this->b = b;
}

void Segment::print()
{
    std::cout<<"a.x: "<<this->a.x<<" , a.y: "<<this->a.y<<std::endl;
    std::cout<<"b.x: "<<this->b.x<<" , b.y: "<<this->b.y<<std::endl;
    std::cout<<std::endl;
}

float Segment::getangle(Point p1, Point p2)
{
   return atan2((p2.y - p1.y),(p2.x - p1.x));
}

Segment* Segment::generatechild()
{

    Segment static children[4];

    Point v = b-a;
    v = v/3;

    //#s0
    Point b1 = a+v;
    children[0].setpoints(a,b1);

     //#s3
    Point b3 = b-v;
    children[3].setpoints(b3,b);

    //#s1
    float angle = getangle(a,b);

    v.rotate(angle + (-PI/3));
    Point b2 = b1+v;
    children[1].setpoints(b1,b2);

     //#s2
    children[2].setpoints(b2,b3);
    return children;
}

void Segment::show()
{
    line(a.x,a.y,b.x,b.y);
}
