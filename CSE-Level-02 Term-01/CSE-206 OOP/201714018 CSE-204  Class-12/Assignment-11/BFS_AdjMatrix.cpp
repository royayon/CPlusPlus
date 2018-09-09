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

class Graph
{
    int **q;
public:
    int v;
    int e;
    Graph(int _v)
    {
        v = _v;
        e = 0;
        q = new int*[v];
        for(int i=0; i<v; i++)
        {
            q[i] = new int[v];
        }
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                q[i][j] = 0;
            }
        }
    }

    void addEdge(int u,int v)
    {
        q[u][v] = 1;
        e++;
    }
    void matrixDisplay()
    {
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                cout<<q[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int *getAdjacentVertices(int u)
    {
        int cnt = 0;
        for(int i=0; i<v; i++)
        {
            if(q[u][i] == 1)
            {
                cnt++;
            }
        }

        int *ret = new int[cnt+1];

        ret[0] = cnt;
        int j=1;
        for(int i=0; i<v; i++)
        {
            if(q[u][i] == 1)
            {
                ret[j++] = i;
            }
        }

        return ret;
    }

    void BFS(int s)
    {
        int *color = new int[v];
        int *d = new int[v];
        int *pi = new int[v];

        for(int i=0; i<v; i++)
        {
            color[i] = WHITE;
            d[i] = INT_MAX;
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
            int *adj = getAdjacentVertices(u);
            int len = adj[0];
            for(int k=1; k<=len; k++)
            {
                if(color[adj[k]] == WHITE)
                {
                    color[adj[k]] = GRAY;
                    d[adj[k]] = d[adj[k]] + 1;
                    pi[adj[k]] = u;
                    Q.enqueue(adj[k]);
                }
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
        cout<<"\nMenu: 1. Add Edge    2.BFS    3.Done!    4.Show Matrix"<<endl;
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
        else if(ch==4)
        {
            g.matrixDisplay();
        }
    }
}


