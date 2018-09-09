#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a , a+n);
    for(int i=0;n!=1;i++)
    {
        if(i%2 == 0)
        {
            n--;
        }
        else
        {
            for(int j=1;j<n;j++)
            {
                a[j-1] = a[j];
            }
            n--;
        }
    }
    cout<<a[0];
}
