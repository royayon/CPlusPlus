#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1;
    for(int i=0;i<s1.length();i++)
    {
        if(s1.at(i)=='a'||s1.at(i)=='e'||s1.at(i)=='i'||s1.at(i)=='o'||s1.at(i)=='u'||s1.at(i)=='A'||s1.at(i)=='E'||s1.at(i)=='I'||s1.at(i)=='O'||s1.at(i)=='U'||s1.at(i)=='y'||s1.at(i)=='Y')
        {

        }
        else
        {
            s2.push_back('.');
            s2.push_back(tolower(s1.at(i)));
        }
    }
    cout<<s2;

}
