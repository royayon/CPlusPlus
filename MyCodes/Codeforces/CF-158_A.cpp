#include<iostream>
using namespace std;
int main()
{
    int n,k,flag=0,cnt=0;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        /*if(arr[i]!=0)
            flag=1;*/
    }
    //if(!flag) cout<<0;
    //else
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=arr[k-1]&&arr[i]!=0)
                cnt++;
        }
        cout<<cnt;
    }
}
