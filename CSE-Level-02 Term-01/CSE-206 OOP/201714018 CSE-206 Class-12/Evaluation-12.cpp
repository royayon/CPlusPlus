#include<iostream>
using namespace std;

class BankAcc
{
protected:
    string acc_no;
    double deposite;
public:
    BankAcc(string _acc_no , double _deposite)
    {
       acc_no = _acc_no;
       deposite = _deposite;
    }
    double get_deposite()
    {
        return deposite;
    }
    virtual void getTotalInfo() = 0;
};


class CurrentAcc : virtual public BankAcc
{
protected:
    double tax_rate;
public:
    CurrentAcc(string _acc_no , double _deposite , double _tax_rate) : BankAcc(_acc_no , _deposite)
    {
        tax_rate = _tax_rate;
    }
    void reduce_tax()
    {
        deposite -= deposite*(tax_rate/100);
    }
};

class SavingsAcc : virtual public BankAcc
{
protected:
    double profit_rate;
public:
    SavingsAcc(string _acc_no , double _deposite , double _profit_rate) : BankAcc(_acc_no , _deposite)
    {
        profit_rate = _profit_rate;
    }
    void incr_profit()
    {
        deposite += deposite*(profit_rate/100);
    }
};


class StudentAcc : public CurrentAcc , public SavingsAcc
{
protected:
    int nid;
public:
    StudentAcc(string _acc_no , double _deposite , double _tax_rate, double _profit_rate , int _nid) : BankAcc(_acc_no , _deposite) , CurrentAcc(_acc_no , _deposite , _tax_rate) , SavingsAcc(_acc_no , _deposite , _profit_rate)
    {
        nid = _nid;
    }
    void getTotalInfo()
    {
        cout<<"Acc No: "<<acc_no <<endl;
        reduce_tax();
        incr_profit();
        cout<<"Total Balance: "<< deposite<<endl;
        cout<<"NID: "<<nid <<endl;
    }
};

void print_info(BankAcc *obj)
{
    obj->getTotalInfo();
}


int main()
{
    StudentAcc SAcc1("11002220",100,20,10,2018);
    SAcc1.getTotalInfo();
}
