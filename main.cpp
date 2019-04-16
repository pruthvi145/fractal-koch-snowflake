#include<iostream>
#include<graphics.h>
#include <vector>

#include "Point.h"
#include "Segment.h"

using namespace std;

vector<Segment> allsegments;

void triangle(Point a, Point b, Point c)
{
    Segment s1(a,b);
    Segment s2(b,c);
    Segment s3(c,a);
    cout<<sizeof(s1)<<endl;
    s1.show();
    s2.show();
    s3.show();
    allsegments.push_back(s1);
    allsegments.push_back(s2);
    allsegments.push_back(s3);
}

void setup()
{
    Point a(300,200);
    Point b(900,200);
    Point c(600,800);
    triangle(a,b,c);
    Point a2(450,300);
    Point b2(750,300);
    Point c2(600,600);

    //triangle(a2,b2,c2);
}
void loop()
{
    vector<Segment> nextchildren;

    for(unsigned i=0; i<allsegments.size(); i++)
    {
        Segment* children = allsegments[i].generatechild();
        for(unsigned j=0; j<4; j++)
            nextchildren.push_back(children[j]);
    }

    allsegments = nextchildren;
    int i;
    for(i=0; i<allsegments.size(); i++)
    {
        cout<<"Drawing..."<<endl;
         //allsegments[i].print();
         allsegments[i].show();
         //delay(1);
    }
    //cout<<i<<endl;
    cout<<allsegments.capacity()<<"Segments Drawn!"<<endl;
}

int main()
{
    initwindow(1200,1200);
    cout<<allsegments.max_size()<<endl;
    cout<<allsegments.capacity()<<endl;

    setup();
    int i=0;
    while(i<10)
    {
        getch();
        cleardevice();
        loop();
        i++;
        cout<<"DONE: "<<i<<endl;
    }
    cout<<"...................HAPPY MOMENTS.................. "<<endl;
    getch();
    closegraph();
    return 0;
}
