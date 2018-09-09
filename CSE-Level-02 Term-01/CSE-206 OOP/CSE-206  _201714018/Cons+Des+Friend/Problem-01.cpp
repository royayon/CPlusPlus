#include<iostream>
using namespace std;

double area(char ch,int a,int b)
{
    if(ch=='t')
    {
        return .5*a*b;
    }
    else if(ch=='r')
    {
        return a*b;
    }
}

class triangle
{
    int base;
    int height;
public:
    triangle(int b=0,int h=0)
    {
        base=b;
        height=h;
    }
    double area()
    {
        return .5*base*height;
    }
    ~triangle()
    {
            cout<<"\n\n\t\tCalculation is Over!\n\n";
    }
};
class rectangle
{
    int width;
    int height;
public:
    rectangle(int w=0,int h=0)
    {
        width=w;
        height=h;
    }
    double area()
    {
        return width*height;
    }
    ~rectangle()
    {
            cout<<"\n\n\t\tCalculation is Over!\n\n";
    }
};

int main()
{
    double result;
    cout<<"You wanna know the Area of==>\n\t1.Triangle(T).\n\t2.Rectangle(R).\n";
    char ch;
    cin>>ch;
    if(ch=='T')
    {
        int base,height;
        cout<<"Input Base and Height: ";
        cin>>base>>height;
        triangle t1(base,height);
        result=t1.area();
    }
    else if(ch=='R')
    {
        int width,height;
        cout<<"Input Width and Height: ";
        cin>>width>>height;
        rectangle r1(width,height);
        result=r1.area();
    }
    cout<<"\n\nThe area of the Rectangle is: "<<result<<"\n\n\n";
}
