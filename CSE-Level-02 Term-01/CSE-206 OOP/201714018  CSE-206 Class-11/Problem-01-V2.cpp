#include<iostream>
#include<string>
using namespace std;
class Device
{
protected:
    string name;
    int power;

public:
    string file;
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
    void operation(Device *obj)
    {
        cout<<obj->file;
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
    void operation(string _file)
    {
        file = _file;
    }
};

void startOperation(Device *obj)
{
    obj->operate();
}

void Operation(Device *obj)
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

    cout<<endl;

    string file;
    cin>>file;

    s1.operation(file);
    p1.operation(&s1);




}
