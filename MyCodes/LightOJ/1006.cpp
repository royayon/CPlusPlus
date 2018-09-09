#include<iostream>
using namespace std;


int main()
{
    long long int a, b, c, d, e, f;
    int n, caseno = 0, cases;
    cin>>cases;
    long long int ara[10000], m;
    while( cases-- )
    {
        cin>>ara[0]>>ara[1]>>ara[2]>>ara[3]>>ara[4]>>ara[5]>>n;
        for(int m=6; m<=n; m++)
             ara[m]=(ara[m-1]+ara[m-2]+ara[m-3]+ara[m-4]+ara[m-5]+ara[m-6])% 10000007;
        cout<<"Case "<<++caseno<<": "<<ara[n] % 10000007<<endl;
    }
    return 0;
}
