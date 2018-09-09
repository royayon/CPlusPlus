#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string s1;
    cin>>s1;
    if(s1.find("1111111")!=std::string::npos  || s1.find("0000000")!=std::string::npos)
        cout<<"YES";
    else
        cout<<"NO";
}
