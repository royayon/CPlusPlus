#include<iostream>
#include<cstring>
using namespace std;

class Person;
class Food;

void checkDiet(Person p,Food carb,Food protein,Food fat);

class Person
{
    string name;
    int reqCal;
public:
    Person(string nam=" ",int rCal=0)
    {
        name=nam;
        reqCal=rCal;
    }
    friend void checkDiet(Person p,Food carb,Food protein,Food fat);

};


class Food
{
    int quant;
    int calPerGram;
public:
    Food(int q=0,int cPG=0)
    {
        quant=q;
        calPerGram=cPG;
    }
    friend void checkDiet(Person p,Food carb,Food protein,Food fat);

};

void checkDiet(Person p,Food carb,Food protein,Food fat)
{
    if((carb.quant * carb.calPerGram)+(protein.quant * protein.calPerGram)+(fat.quant * fat.calPerGram) >= p.reqCal)
    {
        cout<<p.name<<" is on balanced diet."<<endl;
    }
    else
    {
        cout<<p.name<<"'s daily calorie intake is insufficient."<<endl;
    }

}


int main()
{
    Person p1("person1",3500);
    Person p2("person2",2000);

    Food f1(100,10);
    Food f2(100,10);
    Food f3(100,10);

    checkDiet(p1,f1,f2,f3);

    checkDiet(p2,f1,f2,f3);
}
