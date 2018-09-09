#include<iostream>
using namespace std;

class Attendance
{
    int * sheet;
    int totalStudent;
public:
    Attendance(int totalStu=10)
    {
        totalStudent=totalStu;
        sheet=new int[totalStudent];
        for(int i=0;i<totalStudent;i++)
        {
            sheet[i]=1;
        }
    }
    Attendance(const Attendance& cAtt)
    {
        this->totalStudent=cAtt.totalStudent;
        this->sheet=new int[totalStudent];
        for(int i=0;i<totalStudent;i++)
        {
            this->sheet[i]=cAtt.sheet[i];
        }

    }
    void makeAbsent(int roll)
    {
        sheet[roll-1]=0;
    }
    void makePresent(int roll)
    {
        sheet[roll-1]=1;
    }
    int isPresent(int roll)
    {
        if(sheet[roll-1]==0)
        {
            return 0;
        }
        else if(sheet[roll-1]==1)
        {
            return 1;
        }
    }
    void print()
    {
        for(int i=0;i<totalStudent;i++)
        {
            if(sheet[i]==0)
            {
                cout<<"Roll "<<i+1<<" is absent."<<endl;
            }
            else if(sheet[i]==1)
            {
                cout<<"Roll "<<i+1<<" is present."<<endl;
            }
        }
    }
    int getTotalStudent()
    {
        return totalStudent;
    }
    friend Attendance invertAttendance(Attendance a);
    ~Attendance()
    {
        delete sheet;
    }
};

Attendance invertAttendance(Attendance a)
{
    Attendance A(a.totalStudent);
    for(int i=0;i<a.totalStudent;i++)
    {
        if(a.sheet[i]==0)
        {
            A.makePresent(i+1);
        }
        else if(a.sheet[i]==1)
        {
            A.makeAbsent(i+1);
        }
    }
    return A;

}

int main()
{
    Attendance day1;
    day1.makeAbsent(2);
   // day1.print();

    Attendance day2=invertAttendance(day1);
    day2.print();

    Attendance day3=invertAttendance(day2);
    //day3.print();
}
