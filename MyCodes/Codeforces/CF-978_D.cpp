#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,a[100000],dif[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int diffsum = 0;
    int cnt = 0;
    for(int i=0; i<n-1; i++)
    {
        diffsum += abs(a[i+1] - a[i]);
        cnt++;
    }
    cout<<ceil(1.0*diffsum/cnt);
    int d = ceil(1.0*diffsum/cnt);
    int flag = 1;
    for(int i=0; i<n-1; i++)
    {
        int difff = abs(a[i+1] - a[i]);
        if(abs(difff - d)==1)
        {
            a[i+1]++;
        }
        else if(abs(difff - d)==2)
        {
            a[i]--;
            a[i+1]++;
        }
        else if(abs(difff - d)==0)
        {

        }
        else
        {
            break;
            flag=0;
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    if(flag)
    {
        cout;
    }
    else
    {
        cout<<-1;
    }


}
