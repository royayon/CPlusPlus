#include<iostream>
#define WHITE 1
#define GRAY 2
#define BLACK 3

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

struct arr
{
    int val;
    struct arr *next;
};


class Graph
{
    arr *q;
public:
    int v;
    int e;
    Graph(int _v = 0)
    {
        v = _v;
        e = 0;

        q = new arr[v];
    }

    void addEdge(int u, int v)
    {
        arr *newnode = new arr;
        newnode->val = v;
        newnode->next = NULL;

        if(q[u].next == NULL)
        {
            q[u].next = newnode;
        }
        else
        {
            arr *prev = new arr;
            prev = q[u].next;
            while(prev != NULL)
            {
                prev = prev->next;
            }
            prev->next = newnode;
        }
    }


    void BFS(int s)
    {
        int *color = new int[v];
        int *d = new int[v];
        int *pi = new int[v];

        for(int i=0; i<v; i++)
        {
            color[i] = WHITE;
            d[i] = 0;
            pi[i] = 0;
        }

        color[s] = GRAY;
        d[s] = 0;
        pi[s] = 0;

        CircularQueue Q(v);
        Q.enqueue(s);

        while(!Q.isEmpty())
        {
            int u = Q.dequeue();
            cout<<u<<" ";
            arr *adj = q[s].next;
            while(adj->next != NULL)
            {
                if(color[adj->val] == WHITE)
                {
                    color[adj->val] = GRAY;
                    d[adj->val] = d[u]+1;
                    pi[adj->val] = pi[u];
                    Q.enqueue(adj->val);
                }
                adj = adj->next;
            }
            color[u] = BLACK;
        }
    }
};



int main()
{
    int v;
    cout<<"Enter number of Vertices: ";
    cin>>v;
    Graph g(v);
    while(1)
    {
        cout<<"\nMenu: 1. Add Edge    2.BFS    3.Done!"<<endl;
        cout<<"Enter a Choice: ";
        int ch;
        cin>>ch;
        if(ch==1)
        {
            cout<<"\nEnter start Vertice: ";
            int v1;
            cin>>v1;
            cout<<"\nEnter end Vertice: ";
            int v2;
            cin>>v2;
            g.addEdge(v1,v2);



        }
        else if(ch==2)
        {
            int s;
            cout<<"Enter start Vertice for BFS Traversal: ";
            cin>>s;
            g.BFS(s);
        }
        else if(ch==3)
        {
            break;
        }
    }
}
