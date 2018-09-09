#include<iostream>
using namespace std;
int main()
{
    int n,nc;

    cin>>n;
    char s[100];
    nc=n;

    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }

    for(int i=n;i>=0;i--)
    {
        if(s[i]=='1' && s[i-1]=='0') swap(s[i],s[i-1]);
        //if(s[i]=='0' && s[i-1]=='1') swap(s[i],s[i-1]);
        if(s[i]=='1' && s[i-1]=='1')
        {
            for(int j=i;j<n;j++)
            {
                s[j]=s[j+1];
            }
            nc--;
        }
    }
    int c=0;
    for(int i=0;i<nc;i++)
    {
        if(s[i]!='1')
        {
            c++;
        }
    }
    for(int j=0;j<c;j++)
    {
        s[j]=s[j+1];
    }
    for(int i=0;i<nc;i++)
    {
        cout<<s[i];
    }

}
