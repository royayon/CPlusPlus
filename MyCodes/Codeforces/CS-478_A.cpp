#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        sort(s[i].begin(),s[i].end());
    }
    for(int i=0;i<n;i++)
    {
        s[i].erase(std::unique(s[i].begin(), s[i].end()), s[i].end());
    }
    string obj[n]={};
    int flag=1,m=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[i].compare(obj[j])!=0)
            {
                flag=0;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            obj[m++]=s[i];
        }
    }

    cout<<m;


}
