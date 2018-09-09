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

    void componentCount()
    {
        bool *visited = new bool[v];
        for(int i=0; i<v; i++)
        {
            visited[i] = false;
        }
        int grpNo = 1;
        for(int i=0; i<v; i++)
        {
            if(visited[i] == false)
            {
                cout<<"Group No "<<grpNo++<<": ";
                DFS(i,visited);
                cout<<endl;
            }
        }

    }
    void DFS(int s,bool *visited)
    {
        /*bool *visited = new bool[v];
        for(int i=0; i<v; i++)
        {
            visited[i] = 0;
        }*/
        Stack S(100);
        S.push(s);
        while(!S.isEmpty())
        {
            int k = S.pop();
            if(!visited[k])
            {
                cout<<k<<" ";
                visited[k] = true;
            }

            list<int>::iterator it;

            for(it=graph[k].begin() ; it != graph[k].end() ; it++)
            {
                if(visited[*it] == false)
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
        cout<<"\nMenu: 1. Add Edge    2.Done!    3.Number Of Groups"<<endl;
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
        else if(ch==3)
        {
            g.componentCount();
        }
        else if(ch==2)
        {
            break;
        }
    }
}




