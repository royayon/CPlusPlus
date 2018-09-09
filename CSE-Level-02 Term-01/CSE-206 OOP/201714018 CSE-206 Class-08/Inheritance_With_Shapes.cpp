#include<iostream>
using namespace std;

class Rectangle
{
private:
    double length;
protected:
    double height;
public:

    Rectangle(double _height = 0 , double _lenght = 0)
    {
        height = _height;
        length = _lenght;
    }

    virtual double getArea()
    {
        cout<< length*height <<endl;
    }


};

class Triangle : public Rectangle
{
private:
    double base;
public:
    Triangle(double _height = 0 , double _base= 0) : Rectangle(_height)
    {
        base = _base;
    }

    double getArea()
    {
        cout<< .5*height*base <<endl;
    }
};

class Square : public Rectangle
{
public:
    Square(double _height = 0) : Rectangle(_height , _height)
    {

    }

};

void showArea(Rectangle *ptr)
{
    ptr -> getArea();
}

int main()
{
    Triangle t1(10,20);
    showArea(&t1);

    Square s1(5);
    showArea(&s1);

    Rectangle r1(5,10);
    showArea(&r1);
}
