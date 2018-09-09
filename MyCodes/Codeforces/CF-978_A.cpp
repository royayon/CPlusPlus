#include<iostream>
using namespace std;
int main()
{
    int n,a[60];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i != j && a[i]==a[j])
            {
                for(int k=i+1;k<n;k++)
                {
                    a[k-1] = a[k];
                }
                n--;
                i--;
            }
        }
    }
    cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
