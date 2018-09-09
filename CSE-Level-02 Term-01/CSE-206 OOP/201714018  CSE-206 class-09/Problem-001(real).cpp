#include<iostream>
#include<cmath>
using namespace std;
class point
{
protected:
    int x;
    int y;
public:
    point(int _x=0,int _y=0)
    {
        x = _x;
        y = _y;
    }
    double distance(point p)
    {
        double resX = (this->x - p.x)*(this->x - p.x);
        double resY = (this->y - p.y)*(this->y - p.y);
        double res =  sqrt(resX + resY);
        return res;
    }
};

class triangle
{
protected:
    string name;
    point p1;
    point p2;
    point p3;
public:
    triangle(string _name,point _p1,point _p2,point _p3)
    {
        name = _name;
        p1=_p1;
        p2=_p2;
        p3=_p3;
    }
    double getPerimeter()
    {
        return p1.distance(p2)+p2.distance(p3)+p3.distance(p1);
    }
};

class rectangle:public triangle
{
protected:
    string name;
    point p4;
public:
    rectangle(string _name,point _p1,point _p2,point _p3,point _p4):triangle(_name,_p1,_p2,_p3)
    {
        p4 = _p4;
    }
    double getPerimeter()
    {
        return p1.distance(p2)+p2.distance(p3)+p3.distance(p4)+p4.distance(p1);
    }
};

int main()
{
    point p1(0,0),p2(1,1),p3(2,2),p4(3,3);
    triangle t1("a",p1,p2,p3);
    cout<<t1.getPerimeter();

    cout<<endl;

    rectangle r1("b",p1,p2,p3,p4);
    cout<<r1.getPerimeter();

}
