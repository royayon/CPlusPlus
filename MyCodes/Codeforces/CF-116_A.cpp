#include<iostream>
using namespace std;
int main()
{
    int n,a,b,maxp=0,p=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        p = p-a+b;
        maxp=max(p,maxp);
    }
    cout<<maxp;
}
