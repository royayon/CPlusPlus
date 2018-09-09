#include<iostream>
#define MAX 5
using namespace std;

class Stack
{
    int* p;
    int top;
    int len;
public:
    /*Stack()   //for default constructor
    {
        itm = new char[MAX];
        sz= MAX;
        top=0;
    }*/
    Stack(int dynamicSize)
    {
        p= new int[dynamicSize=5];
        len=dynamicSize;
        top=0;
    }
    Stack(const Stack& cst)
    {
        top=cst.top;
        len=cst.len;
        p=new int[cst.len];
        for(int i=0;i<cst.len;i++)
        {
            p[i]=cst.p[i];
        }
        cout<<"Copy Constructor is used.So be cool!!"<<endl;
    }

    void push(int i)
    {
        if(top<len)
        {
            p[top++]=i;
        }
        else
        {
            cout<<"Stack is Overflowed!"<<endl;
        }
        cout<<"Stack now has "<<top<<" elements."<<endl;
    }


    void pop()
    {
        if(top>=0)
        {
            --top;
        }
        else
        {
            cout<<"Stack is Empty!"<<endl;
        }
        cout<<"Stack now has "<<top<<" elements."<<endl;
    }

    char peak()
    {
        if(top>0)
        {
            int ctop=top;
            return p[--ctop];
        }
    }


    void printStack()
    {
        cout<<"The Stack is==>>"<<endl;
        for(int j=top-1;j>=0;j--)
        {
            cout<<p[j]<<endl;
            //cout<<s.peak()<<" ";
        }
    }
    friend void printSum(Stack s);
    ~Stack()
    {
        delete p;
        cout<<"Destructed!"<<endl;
    }

};

void printSum(Stack s)
{
    int sum=0;
    for(int i=0;i<s.top;i++)
    {
        sum+=s.p[i];
    }
    cout<<"The Sum is : "<<sum<<endl;;
}

int main()
{
    cout<<"Give Stack Size : "<<endl;
    int n;
    cin>>n;
    Stack s1(n);

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    s1.printStack();
    printSum(s1);

    s1.pop();
    s1.pop();

    s1.printStack();
    printSum(s1);


}
