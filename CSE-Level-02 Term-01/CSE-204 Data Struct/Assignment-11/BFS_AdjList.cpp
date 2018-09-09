#include<iostream>
#include <list>

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

};

class Graph
{
    int V;
    list<int> *adjList;

public:
    Graph(int _V)
    {
        V = _V;
        adjList = new list<int>[V];
    }

    void addEdge(int v1, int v2)
    {
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }

    void BFS(int s)
    {
        int *color = new int[V];
        int *d = new int[V];
        int *pi = new int[V];

        int WHITE = 0;
        int GRAY = 1;
        int BLACK = 2;

        for(int u = 0; u<V; u++)
        {
            if(u == s)
            {
                continue;
            }
            color[u] = WHITE;
            d[u] = -1;
            pi[u] = -1;
        }

        color[s] = GRAY;
        d[s] = 0;
        pi[s] = -1;

        CircularQueue Q(V);
        Q.enqueue(s);

        while(!Q.isEmpty())
        {
            int u = Q.dequeue();
            //System.out.print(u + " ");
            list<int>::iterator v;
            for(v=adjList[u].begin() ; v != adjList[u].end() ; v++)
            {
                if(color[*v] == WHITE)
                {
                    color[*v] = GRAY;
                    d[*v] = d[u]+1;
                    pi[*v] = u;
                    Q.enqueue(*v);
                }
            }
            color[u] = BLACK;
        }
        for(int i=0; i<V; i++)
        {
            if(i != s)
            {
                if(d[i] != -1)
                {
                    cout<<d[i]*6 << " ";
                }
                else
                    cout<<-1 << " ";
            }
        }
    }
};

int main()
{

    int q;
    cin>>q;
    while(q != 0)
    {
        int n;
        int m;
        cin>>n>>m;
        Graph g(n);
        for(int i = 0; i<m; i++)
        {
            int u;
            int v;
            cin>>u>>v;

               g.addEdge(u-1, v-1);
        }
        int s;
        cin>>s;
        g.BFS(s-1);
        cout<<endl;

        q--;
    }
}


