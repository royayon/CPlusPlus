#include<iostream>
using namespace std;

class Stack
{
    int *ele;
    int top;
    int sz;
public:
    Stack(int _sz=0)
    {
        sz = _sz;
        top = -1;
        ele = new int[sz];
    }
    void push(int val)
    {
        if(top >= sz-1)
        {
            cout<<"Overflowed!"<<endl;
        }
        else
        {
            ele[++top] = val;
        }
    }
    int pop()
    {
        if(top>=0)
        {
            int ret = ele[top];
            --top;
            return ret;
        }
        else
        {
            cout<<"Empty Stack!"<<endl;
        }
    }
    void display()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<ele[i]<<" ";
        }
    }
};

int main()
{
    int n;
    cout<<"Enter Stack Size: ";
    cin>>n;
    Stack s1(n);
    while(1)
    {
        cout<<"\nMenu : 1. Push   2.Pop   3.Display   4.Quit"<<endl;
        cout<<"Enter a Choice: ";
        int ch;
        cin>>ch;
        if(ch==1)
        {
            int val;
            cin>>val;
            s1.push(val);
        }
        else if(ch==2)
        {
            cout<<s1.pop();
        }
        else if(ch==3)
        {
            s1.display();
        }
        else if(ch==4)
        {
            break;
        }
    }
}
