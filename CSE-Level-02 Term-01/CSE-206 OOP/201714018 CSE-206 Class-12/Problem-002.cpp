#include<iostream>
using namespace std;

class ResultSheet
{
    int cse201;
    int cse202;
    int cse204;
public:
    ResultSheet(int _cse201 , int _cse202 , int _cse204)
    {
        cse201 = _cse201;
        cse202 = _cse202;
        cse204 = _cse204;
    }
    friend ResultSheet operator+(ResultSheet left , ResultSheet right);
    friend ResultSheet operator-(ResultSheet left , ResultSheet right);

    void display()
    {
        cout<<"cse201: "<<cse201<<endl;
        cout<<"cse202: "<<cse202<<endl;
        cout<<"cse204: "<<cse204<<endl;
    }

    bool operator==(ResultSheet right)
    {
        if((this->cse201 == right.cse201) && (this->cse202 == right.cse202)&&(this->cse204 == right.cse204))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!=(ResultSheet right)
    {
        if((this->cse201 != right.cse201) && (this->cse202 != right.cse202)&&(this->cse204 != right.cse204))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator>=(ResultSheet right)
    {
        if((this->cse201 >= right.cse201) && (this->cse202 >= right.cse202)&&(this->cse204 >= right.cse204))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator<=(ResultSheet right)
    {
        if((this->cse201 <= right.cse201) && (this->cse202 <= right.cse202)&&(this->cse204 <= right.cse204))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
ResultSheet operator+(ResultSheet left , ResultSheet right)
{
    int newcse201 = left.cse201 + right.cse201;
    int newcse202 = left.cse202 + right.cse202;
    int newcse204 = left.cse204 + right.cse204;
    ResultSheet ret(newcse201,newcse202,newcse204);
    return ret;
}
ResultSheet operator-(ResultSheet left , ResultSheet right)
{
    int newcse201 = left.cse201 - right.cse201;
    int newcse202 = left.cse202 - right.cse202;
    int newcse204 = left.cse204 - right.cse204;
    ResultSheet ret(newcse201,newcse202,newcse204);
    return ret;
}

int main()
{
    ResultSheet rs1(100,200,300);
    ResultSheet rs2(1,2,3);

    ResultSheet rs3 = rs1 + rs2;
    rs3.display();
}
