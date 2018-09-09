#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int flag = 0;
    if(k%2 == 0)
    {
        if((2*(n-2)-k)>=0 && (2*(n-2)-k)%2 == 0)
        {
            flag=1;
        }
    }
    else if(k%2 != 0)
    {
        if((n-2) >= k || 2*(n-2)==k)
        {
            flag = 1;
        }
    }
    int m=k/2;
    int l=k/2;
    int o=k;
    if(flag)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(k%2==0)
                {
                    if((i==1 && j>0 && j<n-1 && m) || (i==2 && j>0 && j<n-1 && l))
                    {
                        cout<<"#";
                        if(i==1) m--;
                        if(i==2) l--;
                    }
                    else
                    {
                        cout<<".";
                    }
                }
                else
                {
                    if((i==1 && j>0 && j<n-1 && o) || (i==2 && j>0 && j<n-1 && o))
                    {
                        cout<<"#";
                        if(i==1) o--;
                        if(i==2) o--;
                    }
                    else
                    {
                        cout<<".";
                    }
                }


            }
            cout<<endl;

        }
    }
    else
        cout<<"NO"<<endl;


}
