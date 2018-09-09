#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
struct strint
{
    int occur;
    string str;
};
int main()
{
    int n;
    string s;
    strint si[1000];
    cin>>n>>s;
    int k=0;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(s[i]==s[j] && s[i+1]==s[j+1])
            {
                cnt++;
            }
            si[k].occur=cnt;
            char s2[2];
            s2[0]=s[i];
            s2[1]=s[i+1];
            si[k].str = s2;
            k++;

        }
    }
    int i, j;
    strint temp;
    for (i = 0; i < k-1; i++)
    {
        for (j = 0; j < k-i-1; j++)
        {
            if (si[j].occur < si[j+1].occur)
            {
                //swap(&si[j], &si[j+1]);
                temp.occur = si[j].occur;
                si[j].occur = si[j+1].occur;
                si[j+1].occur = temp.occur;

                temp.str = si[j].str;
                si[j].str = si[j+1].str;
                si[j+1].str = temp.str;

            }
        }
    }
    string s3=si[0].str;
    cout<<s3.at(0)<<s3.at(1);


}
