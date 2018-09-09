#include<iostream>
using namespace std;
int main()
{
    int n,a,b,c,cnt=0;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c;
        if(a==1&&b==1 ||b==1&&c==1 ||c==1&&a==1) cnt++;
    }
    cout<<cnt;
}
