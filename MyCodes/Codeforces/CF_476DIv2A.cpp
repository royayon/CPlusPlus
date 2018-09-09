#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,n,s,p;
    cin>>k>>n>>s>>p;

    cout<<(long long)ceil((ceil(n*1.0/s))*k*1.0/p);
}
