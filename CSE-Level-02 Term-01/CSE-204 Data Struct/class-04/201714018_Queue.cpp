#include<iostream>
#define MAX 5
using namespace std;

class Queue
{
    int myArr[MAX];
    int counter;
public:
    Queue()
    {
        counter=0;
    }

    void enqueue(int x)
    {
        if(counter<MAX)
        {
            myArr[counter++]=x;
        }
        else
        {
            cout<<"Queue is Overflowed!"<<endl;
        }
    }
    void dequeue()
    {
        if(counter)
        {
            for(int i=1;i<counter;i++)
            {
                myArr[i-1]=myArr[i];
            }
            counter--;
        }
        else
        {
            cout<<"Queue is empty!"<<endl;
        }
    }
    bool isEmpty()
    {
        if(counter==0)
            return true;
        else
            return false;
    }
    int sizeQ()
    {
        return counter;
    }

    void display(Queue Q)
    {
        for(int i=0;i<counter;i++)
        {
            cout<<myArr[i]<<" ";
        }
    }
};


int main()
{
    Queue Q;


    int x=1;
    while(x)
    {
        cout<<"\nChoose an Option: "<<endl;
        cout<<"1. Enqueue."<<endl;
        cout<<"2. Dequeue."<<endl;
        cout<<"3. isEmpty."<<endl;
        cout<<"4. Size."<<endl;
        cout<<"5. Display."<<endl;
        cout<<"6. Quit."<<endl;

        int choice;
        cin>>choice;
        if(choice==1)
        {
            int n;
            cin>>n;
            Q.enqueue(n);
        }
        else if(choice==2)
        {
            Q.dequeue();
        }
        else if(choice==3)
        {
            if(!Q.isEmpty())
                cout<<"Queue is not Empty!"<<endl;
            else
                cout<<"Queue is Empty!"<<endl;
        }
        else if(choice==4)
        {
            cout<<"The size of the Queue is: "<<Q.sizeQ()<<endl;
        }
        else if(choice==5)
        {
            Q.display(Q);
        }
        else if(choice==6)
        {
            x=0;
        }
        else
        {
            cout<<"Wrong Choice!!"<<endl;
        }
    }
}
