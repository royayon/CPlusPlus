#include<iostream>
#include <list>
using namespace std;

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

    void mutualNum(int u,int v)
    {
        list<int>::iterator it;
        list<int>::iterator it1;
        int cnt = 0;
        for(it=graph[u].begin(); it!= graph[u].end(); it++)
        {
            for(it1=graph[v].begin(); it1!= graph[v].end(); it1++)
            {
                if(*it == *it1)
                {
                    cnt++;
                }
            }
        }
        cout<<"\nMutual Friends No: "<<cnt<<" \nMutual Friends Are: "<<endl;
        for(it=graph[u].begin(); it!= graph[u].end(); it++)
        {
            for(it1=graph[v].begin(); it1!= graph[v].end(); it1++)
            {
                if(*it == *it1)
                {
                    cout<<*it<<" ";
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
        cout<<"\nMenu: 1. Add Edge    2.Done!    3.Mutual Friends"<<endl;
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
            int u,v;
            cout<<"\nEnter First Vertex: ";
            cin>>u;
            cout<<"\nEnter Second Vertex: ";
            cin>>v;
            g.mutualNum(u,v);
        }
        else if(ch==2)
        {
            break;
        }
    }
}
