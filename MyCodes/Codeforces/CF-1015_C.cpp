#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int minWays(int diff[], int n, int ndiff)
{
   sort(diff , diff+n, greater<int>());
   for(int i=0;i<n;i++)
   {
       if(diff[i] == ndiff)
       {
           return 1;
       }
       if(diff[i] < ndiff)
       {

       }

   }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int *bcomp = new int[n];
    int *acomp = new int[n];
    int *diff = new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>bcomp[i]>>acomp[i];
        diff[i] = bcomp[i] - acomp[i];
    }
    int atotal = 0;
    int btotal = 0;
    for(int i=0; i<n; i++)
    {
        atotal += acomp[i];
        btotal += bcomp[i];
    }

    if(atotal <= m)
    {
        int ndiff = abs(btotal - m);
        cout<<minWays(diff , n, ndiff);

    }
    else
    {
        cout<<-1;
    }
}
