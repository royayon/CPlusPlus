#include<iostream>
#define MAX 10
using namespace std;

class Stack
{
    int* itm;
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
        itm= new int[dynamicSize];
        sz=dynamicSize;
        top=0;
    }


    void push(int i)
    {
        if(top<sz)
        {
            itm[top++]=i;
        }
        else
        {
            cout<<"Stack is Overflowed!"<<endl;
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
            cout<<"Stack is Empty!"<<endl;
        }
        //cout<<"Stack now has "<<top<<" elements."<<endl;
    }

    int peak()
    {
        if(top>0)
        {
            return itm[--top];
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
    cout<<"Enter the size of the first stack: ";
    int num;
    cin>>num;
    Stack s1(num);

    int x=1;
    while(x)
    {
        cout<<"\nEnter your choice: "<<endl;
        cout<<"1. Push "<<endl;
        cout<<"2. Pop "<<endl;
        cout<<"3. Display "<<endl;
        cout<<"4. End of Stack 1 "<<endl;

        int ch;
        cin>>ch;
        if(ch==1)
        {
            int item;
            cin>>item;
            s1.push(item);
        }
        else if(ch==2)
        {
            s1.pop();
        }
        else if(ch==3)
        {
            cout<<"\n\nYour Stack 1 is ==>"<<endl;
            s1.display(s1);
        }
        else if(ch==4)
        {
            x=0;
        }
        else
        {
            cout<<"Wrong Choice!"<<endl;
        }

    }


    /*for(int j=0;j<n;j++)   //for full stack 1 input
    {
        cout<<"Enter item no. "<<j+1<<" :"<<endl;
        int item;
        cin>>item;
        s1.push(item);
    }

    cout<<"\n\nYour Stack 1 is ==>"<<endl;
    s1.display(s1);*/

    cout<<"Enter the size of the Second stack: ";
    int num1;
    cin>>num1;
    Stack s2(num1);

    for(int j=0;j<num1;j++)   //for full stack 2 input
    {
        cout<<"Enter item no. "<<j+1<<" :"<<endl;
        int item;
        cin>>item;
        s2.push(item);
    }

    cout<<"\n\nYour Stack 2 is ==>"<<endl;
    s2.display(s2);

    s1.mergeStack(s2);
    cout<<"\n\nMerged Stack 1 is==> "<<endl;
    s1.display(s1);


}
