#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
double dist(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main()
{
    int n,m;
    cin>>n>>m;
    int carr[2000][2];
    int darr[2000][2];
    int cats[2000];

    for(int i=0; i<n; i++)
    {
        cin>>carr[i][0]>>carr[i][1];
    }
    for(int i=0; i<m; i++)
    {
        cin>>darr[i][0]>>darr[i][1];
    }

    int mindisindex=0;
    for(int i=0; i<m; i++)
    {
        double mindis = 0.0;

        for(int j=0; j<n; j++)
        {
            double d = dist(carr[j][0],carr[j][1],darr[i][0],darr[i][1]);
            if(mindis > d)
            {
                mindis = d;
            }
            if(mindis == d)
            {
                mindisindex = j;
            }
        }
        cats[mindisindex]++;
    }
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        if(cats[i]==1)
            cnt++;
    }
    cout<<cnt;


}
