#include<iostream>
#include<vector>
#include<graphics.h>
#include<time.h>

#include "Point.h"
#include "Segment.h"

#define PI 3.1415

using namespace std;

vector<Segment> allsegments;

int random(int min, int max) //range : [min, max]
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

void drawallsegments()
{
    for(unsigned i=0; i<allsegments.size(); i++)
    {
        short r = random(1,255);
        short g = random(1,255);
        short b = random(1,255);
        setcolor(COLOR(r,g,b));
        cout<<"Drawing: "<<i<<endl;
        allsegments[i].show();
    }
    cout<<allsegments.capacity()<<" - Segments Drawn!"<<endl;
}

void setup()
{
    Point a(300,200);
    Point b(900,200);
    Point c(600,800);
    Segment s1(a,b);
    Segment s2(b,c);
    Segment s3(c,a);
    allsegments.push_back(s1);
    allsegments.push_back(s2);
    allsegments.push_back(s3);
}

void loop()
{
    getch();
    cleardevice();
    drawallsegments();
    vector<Segment> nextchildren;

    for(unsigned i=0; i<allsegments.size(); i++) //unsigned given more +ve values for loop
    {
        Segment* children = allsegments[i].generatechild();
        for(unsigned j=0; j<4; j++)
            nextchildren.push_back(children[j]);
    }
    allsegments = nextchildren;
}

int main()
{
    initwindow(1200,850);
    setup();
    setcolor(COLOR(38,224,165));
    settextstyle(10,HORIZ_DIR, 4);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(getmaxx()/2,getmaxy()/2,"KOCH - SNOWFLAKES");
    cout<<"...................START DRAWING.................. "<<endl;
    for(short i=1; i<=7 ;i++)
    {
        cout<<"START: "<<i<<endl;
        cout<<"-----------"<<endl;
        loop();
        cout<<"-----------"<<endl;
        cout<<"DONE: "<<i<<endl<<endl;
    }
    cout<<"...................HAPPY MOMENTS!!!................."<<endl;
    getch();
    closegraph();
    return 0;
}
