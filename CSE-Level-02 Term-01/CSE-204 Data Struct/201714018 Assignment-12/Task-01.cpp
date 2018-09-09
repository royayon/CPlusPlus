#include<iostream>
#include <list>
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
    }

    bool isEmpty()
    {
        if(top == -1)
            return 1;
        else
            return 0;
    }


    void display()
    {
        for(int i=0; i<=top; i++)
        {
            cout<<ele[i]<<" ";
        }
    }
};


class Graph
{
    list<int> *graph;
public:
    int v;
    Graph(int _v = 0)
    {
        v = _v;
        graph = new list<int>[v];
    }

    void addEdge(int u,int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    /*void DFS_call()
    {

        int visited[100] = {0};
        for(int i=0; i<v; i++)
        {
            DFS(i,&visited[0]);
        }

    }*/
    void DFS(int s)
    {
        bool *visited = new bool[v];
        for(int i=0; i<v; i++)
        {
            visited[i] = 0;
        }
        Stack S(100);
        S.push(s);
        while(!S.isEmpty())
        {
            int k = S.pop();
            if(!visited[k])
            {
                cout<<k<<" ";
                visited[k] = 1;
            }

            list<int>::iterator it;

            for(it=graph[k].begin() ; it != graph[k].end() ; it++)
            {
                if(visited[*it] == 0)
                {
                    S.push(*it);
                }
            }
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
        cout<<"\nMenu: 1. Add Edge    2.DFS(Single Vertex)    3.Done!"<<endl;
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
            g.DFS(s);
        }
        else if(ch==3)
        {
            break;
        }
    }
}



