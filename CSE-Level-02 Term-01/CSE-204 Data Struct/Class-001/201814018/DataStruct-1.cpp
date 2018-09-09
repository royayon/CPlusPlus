#include<iostream>
#include<cstdlib>
using namespace std;

struct dynamic_Array
{
    int *p;
    int initialize(int n)
    {
        p=(int*)malloc(n*sizeof(int));
    }

    int input()
    {

    }

};
int main()
{
    int x;
    cout<<"Enter the size: ";
    cin>>x;
    struct dynamic_Array d;
    d.initialize(x);

}
