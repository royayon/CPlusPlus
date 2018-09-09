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
        int start,endp;
        cin>>start>>endp;
        for(int j = start; j<=endp; j++)
        {
            res[j-1] = 1;
        }
    }
    int count = 0;
    for(int i = 0; i<m; i++)
    {
        if(res[i] == 0)
            count++;
    }
    cout<<count<<endl;
    if(count!=0)
    {
        for(int i = 0; i<m; i++)
        {
            if(res[i] == 0)
                cout<<i+1<<" ";
        }
    }
}
