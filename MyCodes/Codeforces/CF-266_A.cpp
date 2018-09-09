#include<iostream>
using namespace std;
int main()
{
    int n;
    int preR=0,preG=0,preB=0,cnt=0;
    char ch;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ch;
        if(ch=='R' && preR) cnt++;
        else if(ch=='G' && preG) cnt++;
        else if(ch=='B' && preB) cnt++;


        if(ch=='R') preR=1;
        else  preR=0;

        if(ch=='G') preG=1;
        else  preG=0;

        if(ch=='B') preB=1;
        else  preB=0;
    }
    cout<<cnt;

}
