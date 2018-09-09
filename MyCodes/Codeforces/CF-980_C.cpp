#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[100000];
    int res[100000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]%k == 0)
        {
            res[i] = arr[i];
        }
        else
        {
            res[i] = k*(arr[i]/k);
        }

    }
    for(int i=0;i<n;i++)
    {
        cout<<res[i]<<" ";
    }

}
