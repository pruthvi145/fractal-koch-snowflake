#ifndef SEGMENT_H
#define SEGMENT_H

#include<graphics.h>
#include<iostream>
#include "Point.h"
#include<vector>

using namespace std;

class Segment
{
    private:
        Point a;
        Point b;

    public:
        Segment();

        Segment(Point, Point);
        Segment(const Segment&);
        void setpoints(Point, Point);
        Segment* generatechild();
        float getangle(Point, Point);
        void show();
        void print();

    protected:

};

#endif // SEGMENT_H
