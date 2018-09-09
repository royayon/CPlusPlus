#include<iostream>
#include<cmath>
using namespace std;
class Line
{
    int segments;
    int *x;
    int *y;
public:
    Line(int n)
    {
        segments = n;
        x= new int[n];
        y= new int[n];
    }
    Line(const Line& cLine)
    {
        segments = cLine.segments;
        x= new int[segments+1];
        y= new int[segments+1];

        for(int i=0;i<segments+1;i++)
        {
            x[i]=cLine.x[i];
            y[i]=cLine.y[i];
        }
    }

    void setPoint(int i,int _x,int _y)
    {
        x[i]=_x;
        y[i]=_y;
    }
    friend double getLength(Line l);

    ~Line()
    {
        delete []x;
        delete []y;
    }
};
double getLength(Line l)
{
    double len=0;
    for(int i=0;i<l.segments;i++)
    {
        len+= sqrt((l.x[i+1] - l.x[i])*(l.x[i+1] - l.x[i])  +  (l.y[i+1] - l.y[i])*(l.y[i+1] - l.y[i]));
    }
    return len;
}

int main()
{
    cout<<"Number of Segments:"<<endl;
    int n;
    cin>>n;
    Line l1(n);

    for(int i=0; i<n+1; i++)
    {
        cout<<"Point-"<<i<<": ";
        int x,y;
        cin>>x>>y;
        l1.setPoint(i,x,y);
    }
    cout<<"Length: "<<getLength(l1);
}
