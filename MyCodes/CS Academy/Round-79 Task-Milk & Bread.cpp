#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int m,b,y,res=0;
    cin>>m>>b>>y;
    if(abs(m-y)<abs(b-y))
    {
        res = abs(m-y);
        res+= abs(m-b);
    }
    else if(abs(m-y)>=abs(b-y))
    {
        res = abs(b-y);
        res+= abs(b-m);
    }
    cout<<res;

}
