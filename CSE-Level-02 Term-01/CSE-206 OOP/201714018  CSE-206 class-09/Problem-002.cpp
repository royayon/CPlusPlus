#include<iostream>
#include<cstring>
using namespace std;
class human
{
protected:
    string name;
    int age;
public:
    human(string _name,int _age)
    {
        name = _name;
        age = _age;
    }
};

class student
{
protected:
    int roll;
    int courseNo;
public:
    student(int _roll,int _courseNo)
    {
        roll = _roll;
        courseNo = _courseNo;
    }
};

class Marks:public human , public student
{
protected:
    int *marks;
    double *cgpa;
    double cg;
public:
    Marks(string name,int age,int roll,int courseNo):human(name,age),student(roll,courseNo)
    {
        marks = new int[courseNo];
        cgpa = new double[courseNo];
        cg = 0;
        setMarks();
    }
    void setMarks()
    {
        int mark;
        cout<<"Give Marks:"<<endl;
        for(int i=0;i<courseNo;i++)
        {
            cin>>mark;
            marks[i] = mark;
        }
        setCGPA();
    }
    void setCGPA()
    {
        for(int i=0;i<courseNo;i++)
        {
            if(marks[i] >= 80 && marks[i] <= 100)  cgpa[i] = 4.00;
            else if(marks[i] >= 75 && marks[i] < 80)  cgpa[i] = 3.75;
            else if(marks[i] >= 70 && marks[i] < 75)  cgpa[i] = 3.50;
            else if(marks[i] >= 65 && marks[i] < 70)  cgpa[i] = 3.25;
            else if(marks[i] >= 60 && marks[i] < 65)  cgpa[i] = 3.00;
            else if(marks[i] >= 55 && marks[i] < 60)  cgpa[i] = 2.75;
            else if(marks[i] >= 50 && marks[i] < 55)  cgpa[i] = 2.50;
            else if(marks[i] >= 0 && marks[i] < 50)  cgpa[i] = 0.00;
        }
        double sum=0;
        for(int i=0;i<courseNo;i++)
        {
            sum+= cgpa[i];
        }
        cg=sum/courseNo;
    }

    void show()
    {
        cout<<"Student Name : "<<name<<endl;
        cout<<"Student Age : "<<age<<endl;
        cout<<"Student Roll : "<<roll<<endl;
        cout<<"Student Course No : "<<courseNo<<endl;
        cout<<"Student CGPA : "<<cg<<endl;
        cout<<"Student Marks : "<<endl;
        for(int i=0;i<courseNo;i++)
        {
            cout<<marks[i]<<" ";
        }

    }

};

int main()
{
    int dummy;
    string name;
    int age;
    int roll;
    int courseNo;
    cout<<"\nInput Student Name: ";
    //cin>>name;
    getline(cin,name);
    cout<<"\nInput Student Age: ";
    cin>>age;
    cout<<"\nInput Student Roll: ";
    cin>>roll;
    cout<<"\nInput Student Course No: ";
    cin>>courseNo;
    Marks m1(name,age,roll,courseNo);
    m1.show();


}
