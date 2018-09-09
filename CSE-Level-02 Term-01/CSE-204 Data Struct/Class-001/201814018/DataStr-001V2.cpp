#include<iostream>
#include<cstdlib>
using namespace std;


int *p;
int occupied;

int initialize(int n)
{
    p=(int*)malloc(n*sizeof(int));
    occupied=0;
}

void append(int val)
{
    p[occupied++]=val;
}

void insertFirst(int val)
{
    for(int i=occupied-1;i>=0;i--)
    {
        p[i+1]=p[i];
    }
    p[0]=val;
    occupied++;
}

void printArray()
{
    for(int i=0;i<occupied;i++)
    {
        cout<<p[i]<<" ";
    }
}
void deleteLast()
{
    occupied=occupied-1;
}
void deleteFirst()
{
    for(int i=1;i<=occupied-1;i++)
    {
        p[i-1]=p[i];
    }
    occupied--;
}

int main()
{
    int x;
    cout<<"Enter the size: ";
    cin>>x;
    initialize(x);

    for(int i=0;i<x;i++)
    {
        int value;
        cin>>value;
        append(value);
    }
    printArray();

    cout<<"\n";

    int val;
    cin>>val;
    insertFirst(val);
    printArray();

    cout<<"\n";

    deleteLast();
    printArray();

    cout<<"\n";

    deleteFirst();
    printArray();


}

