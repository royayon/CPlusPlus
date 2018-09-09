#include<iostream>
#define MAX 5
using namespace std;

class Queue
{
    int myArr[MAX];
    int start;
    int endd;
    int sz=MAX;
    int cnt=0;
public:
    Queue()
    {
        start= -1;
        endd=-1;
    }
    //Using Circular Queue
    void enqueue(int x)
    {
        if((start==0 && endd==sz-1) || (endd==start-1))
        {
            cout<<"Queue is Overflowed!"<<endl;
            return;
        }
        else if(start==-1)  //for first element
        {
            start=endd=0;
            myArr[endd]=x;
        }
        else if((start!=0 && endd==sz-1))  //for circular element
        {
            endd=0;
            myArr[endd]=x;
        }
        else
        {
            endd++;
            myArr[endd]=x;
        }
        cnt++;
    }
    void dequeue()
    {
        if(start==-1)
        {
            cout<<"Queue is empty!"<<endl;
            return;
        }
        if(start==endd)  //last element's dequeue
        {
            start=endd=-1;
        }
        else if(start==sz-1)  //circularly dequeue //by AYON ROY
        {
            start=0;
        }
        else
        {
            start++;
        }
        cnt--;
    }
    bool isEmpty()
    {
        if(endd==-1)
            return true;
        else
            return false;
    }
    int sizeQ()
    {
        return cnt;
    }

    void display()
    {
        if(start==-1)
        {
            cout<<"Queue is empty!"<<endl;
        }
        cout<<"Elements in the Queue: "<<endl;
        if(start<=endd)
        {
            for(int i=start;i<=endd;i++)
                cout<<myArr[i]<<endl;
        }
        else
        {
            for(int i=start;i<=sz-1;i++)
                cout<<myArr[i]<<endl;
            for(int i=0;i<=endd;i++)
                cout<<myArr[i]<<endl;
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
            Q.display();
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

