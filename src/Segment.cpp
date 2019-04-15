#include "Segment.h"
#define PI 3.1415


Segment::Segment(){}

Segment::Segment(Point a, Point b)
{
    this->a = a;
    this->b = b;
}

Segment::Segment(const Segment& s)
{
    this->a = s.a;
    this->b = s.b;
}

void Segment::setpoints(Point a, Point b)
{
    this->a = a;
    this->b = b;

}

void Segment::show()
{
    setcolor(WHITE);
    line(a.x,a.y,b.x,b.y);
}

void Segment::print()
{
    cout<<"a.x: "<<this->a.x<<" , a.y: "<<this->a.y<<endl;
    cout<<"b.x: "<<this->b.x<<" , b.y: "<<this->b.y<<endl;
    cout<<endl;

}

float Segment::getangle(Point p1, Point p2)
{
   float res;
   float m = (p2.y - p1.y)/(p2.x - p1.x);
   res = atan2((p2.y - p1.y),(p2.x - p1.x));
   return res;
}
Segment* Segment::generatechild()
{

    Segment static children[4];

    Point v = b-a;
    v = v/3;

    //#0
    Point b1 = a+v;
    children[0].setpoints(a,b1);

     //#3
    Point b3 = b-v;
    children[3].setpoints(b3,b);

    //#1
    float angle = getangle(a,b);

    v.rotate(angle + (-PI/3));
    Point b2 = b1+v;
    children[1].setpoints(b1,b2);

     //#2
    children[2].setpoints(b2,b3);
    return children;
}
