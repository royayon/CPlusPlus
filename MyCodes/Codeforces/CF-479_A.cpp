#include<iostream>
#include<string>
using namespace std;
int digitcnt(int n1)
{
    int cnt=0;
    while(n1)
    {
        cnt++;
        n1/=10;
    }
    return cnt;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int n1=n;
    int result=n;
    while(k--)
    {
        if(digitcnt(result)==1)
        {
            result--;
        }
        else if(digitcnt(result)>=2 && result%10==0)
        {
            result=result/10;
        }
        else if(digitcnt(result)>=2 && result%10!=0)
        {
            result--;
        }
    }
    cout<<result;
}
