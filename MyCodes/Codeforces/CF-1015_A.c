#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int *res = new int[m];
    for(int i = 0; i<m; i++)
    {
        res[i] = 0;
    }
    for(int i = 0; i<n; i++)
    {
        int start,end;
        cin>>start>>end;
        for(int j = start; j<=end; j++)
        {
            res[j] = 1;
        }
    }
    int count = 0;
    for(int i = 0; i<m; i++)
    {
        if(res[i] == 1)
            count++;
    }
    cout<<count<<endl;
    if(count)
    {
        for(int i = 0; i<m; i++)
        {
            if(res[i] == 1)
                cout<<res[i]<<" ";
        }
    }
}
