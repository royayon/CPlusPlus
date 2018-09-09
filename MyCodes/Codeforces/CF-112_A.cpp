#include<iostream>
#include<cstring>
#include <algorithm>
#include<string>
using namespace std;
int main()
{
    string s1,s2,s3,s4;
    cin>>s1;
    cin>>s2;

    transform(s1.begin(),s1.end(),s1.begin(),::tolower);
    transform(s2.begin(),s2.end(),s2.begin(),::tolower);

    cout<<s1.compare(s2);
}
