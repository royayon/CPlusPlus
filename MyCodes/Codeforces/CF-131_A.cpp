#include<iostream>
#include<cctype>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i=1;
    while(isupper(s[i]))
    {
        i++;
    }
    if(i==s.length()&&islower(s[0]))
    {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        s[0]=toupper(s[0]);
        cout<<s;
    }
    else if(i==s.length()&&isupper(s[0]))
    {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        cout<<s;
    }
    else
    {
        cout<<s;
    }

}
