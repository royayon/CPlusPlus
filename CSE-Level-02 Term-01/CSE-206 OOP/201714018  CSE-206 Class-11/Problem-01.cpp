#include<iostream>
using namespace std;
class Device
{
protected:
    string name;
    int power;
public:
    virtual void operate() = 0;
};

class Printer : public Device
{
public:
    Printer(string _name , int _power)
    {
        name = _name;
        power = _power;
    }
    void operate()
    {
        cout<<"Device Name: "<<this->name<<endl;
        cout<<"Device Power: "<<this->power<<endl;
        cout<<"Device Operation: prints a document"<<endl;
    }
};

class Scanner : public Device
{
public:
    Scanner(string _name , int _power)
    {
        name = _name;
        power = _power;
    }
    void operate()
    {
        cout<<"Device Name: "<<this->name<<endl;
        cout<<"Device Power: "<<this->power<<endl;
        cout<<"Device Operation: scans a document"<<endl;
    }
};

void startOperation(Device *obj)
{
    obj->operate();
}

int main()
{
    Printer p1("Printer-01" , 2000);

    p1.operate();

    cout<<endl;


    Scanner s1("Scanner-01" , 1000);

    s1.operate();

    cout<<endl;

    startOperation(&p1);





}
