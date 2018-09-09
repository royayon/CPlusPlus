#include<iostream>
#define M 2000
using namespace std;
int main()
{
    int n,m;

    char ch;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ch;
            a[i][j] = ch-'0';
        }
    }
    int flag2 = 0;
    for(int row=0;row<n;row++)
    {
        int flag1 = 0;
        for(int col=0;col<m;col++)
        {
            int flag = 0;
            for(int row1=0;row1<n;row1++)
            {
                if(a[row][col] == a[row1][col])
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if(flag) flag1 = 1;
            else
            {
                flag1 = 0;
                break;
            }
        }
        if(flag1) flag2=1;
        else flag2=0;
    }
    if(flag2)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }



}
