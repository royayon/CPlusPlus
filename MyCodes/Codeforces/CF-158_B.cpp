#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,a[5]={};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int s;
        cin>>s;
        a[s]++;
    }
    a[1]=max(a[1]-a[3],0);
    cout<<a[3]+a[4]+(a[1]+2*a[2]+3)/4;
}
