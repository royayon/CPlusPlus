#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t,a=0;
    cin>>t;
    string s[t];
    for(int i=0;i<t;i++)
    {
        cin>>s[i];
        if(s[i]=="X++") a++;
        else if(s[i]=="X--") a--;
        else if(s[i]=="++X") ++a;
        else if(s[i]=="--X") --a;
    }
    cout<<a;
}
