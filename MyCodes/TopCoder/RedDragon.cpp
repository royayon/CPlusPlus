#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool Reddreagon(int i,int c,int n)
{
    int sum=0;
    sum=ceil(i/2);
    int ch=floor((i-(sum))/c);

    if((sum+ch*c)>=i)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    int c,n;
    cin>>c>>n;
    int i=2*c*n;
    int k;
    for(k=i+1;k<=2*i;k++)
    {
        if(Reddreagon(k,c,n)==0)
            break;
    }

    cout<<k;

}
