#ifndef POINT_H
#define POINT_H

#include<iostream>
#include<math.h>

class Point
{
    public:
        int x,y;
        Point(); //default constructor
        Point(int, int);

        void print();
        void rotate(float);

        Point operator+(Point);
        Point operator-(Point);
        Point operator/(int);

};

#endif // POINT_H
