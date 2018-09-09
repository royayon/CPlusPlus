#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1;
    for(int i=0;i<s1.length();i++)
    {
        if(s1.at(i)!='+') s2.push_back(s1.at(i));
    }
    s1="";
    sort(s2.begin(),s2.end());
    for(int i=0;i<s2.length();i++)
    {
        s1.push_back(s2.at(i));
        if(i!=s2.length()-1) s1.push_back('+');
    }
    cout<<s1;
}
