#include<iostream>
#include<cmath>
using namespace std;

class Point
{
    int x;
    int y;

public:
    Point(int x=0,int y=0)
    {
        this->x = x;
        this->y = y;
    }

    Point* shiftBy(int dx,int dy)
    {
        this->x = this->x + dx;
        this->y = this->y + dy;
        return this;
    }
    void print()
    {
        cout<<"Co-Ordinates are: "<<endl;
        cout<<"x => "<<x<<endl;
        cout<<"y => "<<y<<endl;
    }
    friend double distance1(Point p1,Point p2);
    ~Point()
    {
        //cout<<"An Object is destroyed!"<<endl;
        x=0;y=0;
    }

};

double distance1(Point p1,Point p2)
{
    double dis;
    int x1=p1.x;
    int y1=p1.y;
    int x2=p2.x;
    int y2=p2.y;

    dis=pow(((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)),.5);
    return dis;

}


int main()
{
    cout<<"Enter your P1: "<<endl;
    int x1,y1;
    cin>>x1>>y1;
    Point p1(x1,y1);
    p1.print();

    cout<<"Enter your Shifting Co-Ordinates: "<<endl;
    int x2,y2;
    cin>>x2>>y2;
    p1.shiftBy(x2,y2);
    p1.print();

    Point p2(5,5);
    Point p3(2,2);
    double dis=distance1(p2,p3);
    cout<<"Distance is = "<<dis<<endl;

}
