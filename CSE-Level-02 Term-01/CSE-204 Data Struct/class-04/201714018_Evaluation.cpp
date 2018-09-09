#include<iostream>
#define MAX 10
using namespace std;

class Stack
{
    char* itm;
    int top;
    int sz;
public:
    /*Stack()   //for default constructor
    {
        itm = new int[MAX];
        sz= MAX;
        top=0;
    }*/
    Stack(int dynamicSize)
    {
        itm= new char[dynamicSize];
        sz=dynamicSize;
        top=0;
    }

    void push(char i)
    {
        if(top<sz)
        {
            itm[top++]=i;
        }
        else
        {
            //cout<<"Stack is Overflowed!"<<endl;
        }
        //cout<<"Stack now has "<<top<<" elements."<<endl;
    }


    void pop()
    {
        if(top>0)
        {
            --top;
        }
        else
        {
            //cout<<"Stack is Empty!"<<endl;
        }
        //cout<<"Stack now has "<<top<<" elements."<<endl;
    }

    char peak()
    {
        if(top>0)
        {
            int ctop=top;
            return itm[--ctop];
        }
    }


    void display(Stack s)
    {
        //cout<<"The Stack is==>>"<<endl;
        for(int j=top-1;j>=0;j--)
        {
            //cout<<itm[j]<<endl;
            cout<<s.peak()<<" ";
        }
    }

    void mergeStack(Stack s2)
    {
        for(int j=0;j<s2.sz;j++)
        {
            //this->itm[this->top +j]= itm[j];
            if(this->sz >= top+j-2)
            {
                this->push(s2.peak());
            }
        }
    }

};


int main()
{
    cout<<"Enter input size: ";
    int n;
    cin>>n;
    Stack s1(n);
    char* arr= new char[n];

    int i;
    for(i=0;i<n;i++)
    {
        char ch;
        cin>>ch;
        if(ch=='['||ch==']'||ch=='{'||ch=='}'||ch=='('||ch==')')
        {
            arr[i]=ch;
        }
    }

    int flag=0;

    int j;
    for(j=0;j<n;j++)
    {
        if(arr[j]=='['||arr[j]=='{'||arr[j]=='(')
        {
            s1.push(arr[j]);
            flag=0;
        }
        else if(arr[j]==']'||arr[j]=='}'||arr[j]==')')
        {
            if((arr[j]==']'&& s1.peak()=='[') || (arr[j]=='}'&& s1.peak()=='{') || (arr[j]==')'&& s1.peak()=='(') )
            {
                flag=1;
                s1.pop();
            }
            else
            {
                flag=0;
                break;
            }
        }
    }
    if(flag==1)
        cout<<"Valid Expression."<<endl;
    else if(flag==0)
        cout<<"Invalid Expression."<<endl;

}

