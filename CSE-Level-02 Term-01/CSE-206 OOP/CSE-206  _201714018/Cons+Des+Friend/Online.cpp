#include<iostream>
using namespace std;
class bus
{
    public:
    int v_bus;
    int cost_bus;
    friend int time();
    friend int cost();

    bus(int V=0,int C=0)
    {
        v_bus=V;
        cost_bus=C;
    }
};
class train
{
    public:
    int v_train;
    int cost_train;
    friend int time();
    friend int cost();

    train(int V=0,int C=0)
    {
        v_train=V;
        cost_train=C;
    }
};
inline int time(int d,train t1,bus b1)
{
    double tTrain=(t1.v_train/d);
    double tBus=(b1.v_bus/d);
    if(tTrain<tBus)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
inline int cost(int d,train t1,bus b1)
{
    if((t1.cost_train*d)>(b1.cost_bus*d))
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
int main()
{
    cout<<"Set velocity and cost for Train: ";
    int vt,ct;
    cin>>vt>>ct;
    train t1(vt,ct);

    cout<<"Set velocity and cost for Bus: ";
    int vb,cb;
    cin>>vb>>cb;
    bus b1(vb,cb);

    cout<<"Give the Distance: ";
    int d;
    cin>>d;

    cout<<"Which one you want to knoc:\n\t1.Minimum Time(T).\n\t2.Minimum Cost(C)\n";
    char ch;
    cin>>ch;

    if(ch=='T')
    {
        if(time(d,t1,b1)==1)
            cout<<"Train";
        else if(time(d,t1,b1)==2)
            cout<<"Bus";
    }
    else if(ch=='C')
    {
        if(cost(d,t1,b1)==1)
            cout<<"Train";
        else if(cost(d,t1,b1)==2)
            cout<<"Bus";
    }
    else
    {
        cout<<"\nInvalid Input!\n";
    }
}
