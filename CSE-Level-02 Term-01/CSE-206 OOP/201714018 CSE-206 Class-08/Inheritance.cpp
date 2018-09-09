#include<iostream>
#include<cstring>
using namespace std;

class Subject
{
private:
    string teacher_name;
protected:
    double credit_hour;
public:
    int course_id;

    Subject(string name , int crs_id , double hour)
    {
        teacher_name = name;
        credit_hour = hour;
        course_id = crs_id;
    }

    void print_teachers_name()
    {
        cout<<"Teachers name is: "<<teacher_name<<endl;
    }
};

class Sessional : public Subject
{
public:
    Sessional(string name , int crs_id , double hour) : Subject(name,crs_id,hour)
    {

    }
    void calculate_salary()
    {
        cout<<"Salary: "<<25000*credit_hour<<"/="<<endl;
    }
};

class Theory : public Subject
{
public:
    Theory(string name , int crs_id , double hour) : Subject(name,crs_id,hour)
    {

    }
    void calculate_salary()
    {
        cout<<"Salary: "<<35000*credit_hour<<"/="<<endl;
    }
};


int main()
{
    Sessional a("Instructor1",206,.75);
    a.print_teachers_name();
    a.calculate_salary();

    Theory b("Instructor2",205,3);
    b.print_teachers_name();
    b.calculate_salary();
}
