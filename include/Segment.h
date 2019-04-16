#ifndef SEGMENT_H
#define SEGMENT_H

#include<iostream>
#include<vector>
#include<graphics.h>

#include "Point.h"

class Segment
{
    private:
        Point a;
        Point b;

    public:
        Segment();
        Segment(Point, Point);

        void setpoints(Point, Point);
        void print();
        Segment* generatechild();
        float getangle(Point, Point);
        void show();
};

#endif // SEGMENT_H
