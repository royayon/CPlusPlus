#include<iostream>
using namespace std;

class CircularQueue
{
    int *ele;
    int front;
    int rear;
    int sz;
public:
    CircularQueue(int _sz = 0)
    {
        sz = _sz;
        front = rear = -1;
        ele = new int[sz];
    }
    int isEmpty()
    {
        if(front == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void enqueue(int val)
    {
        if((front == rear + 1) || (front == 0 && rear == sz-1))
        {
            cout<<"Overflowed!"<<endl;
        }
        else
        {
            if(front == -1) front = 0;
            rear = (rear + 1) % sz;
            ele[rear] = val;
        }
    }
    int dequeue()
    {
        int ret;
        if(front == -1)
        {
            cout<<"Empty Queue!!"<<endl;
            return -1;
        }
        else
        {
            ret = ele[front];
            if(front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % sz;
            }
        }
        return ret;
    }

    void display()
    {
        if(front == -1)
        {
            cout<<"Empty Queue!!"<<endl;
        }
        else
        {
            int i;
            for(i = front; i!=rear; i=(i+1)%sz)
            {
                cout<<ele[i]<<" ";
            }
            cout<<ele[i];
        }
    }
};

int main()
{
    int n;
    cout<<"Enter Queue Size: ";
    cin>>n;
    CircularQueue CQ1(n);
    while(1)
    {
        cout<<"\nMenu : 1. EnQueue   2.DeQueue   3.Display   4.Quit"<<endl;
        cout<<"Enter a Choice: ";
        int ch;
        cin>>ch;
        if(ch==1)
        {
            int val;
            cin>>val;
            CQ1.enqueue(val);
        }
        else if(ch==2)
        {
            cout<<CQ1.dequeue();
        }
        else if(ch==3)
        {
            CQ1.display();
        }
        else if(ch==4)
        {
            break;
        }
    }
}
