#include<iostream>
using namespace std;
class Vehicle
{
protected:
    string name;
public:
    virtual int totalIncome() = 0;
};

class MotorVehicle : public Vehicle
{
protected:
    int noTrip;
public:
    virtual int totalIncome() = 0;
};

class Car : public MotorVehicle
{
    int rentPerTrip;
public:
    Car(int _noTrip , int _rentPerTrip)
    {
        noTrip = _noTrip;
        rentPerTrip = _rentPerTrip;
    }
    int totalIncome()
    {
        return noTrip*rentPerTrip;
    }
};

class Bus : public MotorVehicle
{
    int noPassenger;
    int rentPerPassenger;
public:
    Bus(int _noTrip , int _noPassenger , int _rentPerPassenger)
    {
        noTrip = _noTrip;
        noPassenger = _noPassenger;
        rentPerPassenger = _rentPerPassenger;
    }
    int totalIncome()
    {
        return noTrip*noPassenger*rentPerPassenger;
    }
};

int printTotal(Vehicle *obj)
{
    return obj->totalIncome();
}
int main()
{
    int a,b,c,d,e;
    cout<<"No of Car Trip: "<<endl;  cin>>a;
    cout<<"Rent Per Trip (Car): "<<endl;  cin>>b;
    cout<<"No of Bus Trip: "<<endl;  cin>>c;
    cout<<"No of Passenger: "<<endl;  cin>>d;
    cout<<"Rent Per Passenger (Bus): "<<endl;  cin>>e;
    Car c1(a,b);
    Bus b1(c,d,e);
    cout<<"Total Income(Car): "<<printTotal(&c1)<<" tk"<<endl;
    cout<<"Total Income(Bus): "<<printTotal(&b1)<<" tk"<<endl;
    cout<<"Total Income: "<<printTotal(&c1) + printTotal(&b1)<<" tk";
}
