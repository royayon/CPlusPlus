#include<iostream>
#include<cmath>
using namespace std;

class top
{
protected:
    int a;
public:
    top(int _a)
    {
        a = _a;
    }
    virtual int getArea() = 0;
};

class left : virtual public top
{
protected:
    int b;
public:
    left(int _a , int _b) : top(_a)
    {
        b = _b;
    }
    virtual int getArea() = 0;
};

class right : virtual public top
{
protected:
    int c;
public:
    right(int _a , int _c) : top(_a)
    {
        c = _c;
    }
    virtual int getArea() = 0;
};

class bottom : public left , public right
{
protected:
    int d;
public:
    bottom(int _a , int _b , int _c , int _d ) : top(_a) , left(_a , _b) , right(_a , _c)
    {
        d = _d;
    }
    int getArea()
    {
        return abs(a-d)*abs(b-c);
    }
};

void print(top* ptr)
{
    cout<<ptr->getArea()<<endl;
}

int main()
{
    cout<<"Input a: ";
    int a;
    cin>>a;

    cout<<"Input b: ";
    int b;
    cin>>b;

    cout<<"Input c: ";
    int c;
    cin>>c;

    cout<<"Input d: ";
    int d;
    cin>>d;

    bottom obj1(a,b,c,d);
    print(&obj1);

}
