#include<iostream>
using namespace std;
int main()
{
    int k,n,w;
    cin>>k>>n>>w;
    if(((((w+1)*w)/2)*k - n)>0)
        cout<<((((w+1)*w)/2)*k - n);
    else
        cout<<0;
}
