#include<iostream>
#include<cstdlib>
using namespace std;
int *p;
int BinSearch(int val,int l,int r)
{
    if(r>=l)
    {
        int mid = l+(r-l)/2;
        if(p[mid]==val)
            return mid;
        if(p[mid]>val)
            return BinSearch(val,l,mid-1);

        return BinSearch(val,mid+1,r);
    }
    return -1;

}
int First_OccurWith_BinSearch(int val,int low,int high,int sz)
{
    if(high>=low)
    {
        int mid=low+(high-low)/2;
        if(mid==0 || p[mid-1]<val && p[mid]==val)
            return mid;
        else if(p[mid]<val)
            return First_OccurWith_BinSearch(val,mid+1,high,sz);
        else
            return First_OccurWith_BinSearch(val,low,mid-1,sz);

    }
    return -1;

}
int Last_OccurWith_BinSearch(int val,int low,int high,int sz)
{
    if(high>=low)
    {
        int mid=low+(high-low)/2;
        if(mid==sz-1 || val<p[mid+1] && p[mid]==val)
            return mid;
        else if(p[mid]>val)
            return Last_OccurWith_BinSearch(val,low,mid-1,sz);
        else
            return Last_OccurWith_BinSearch(val,mid+1,high,sz);
    }
    return -1;
}
int OccurWith_BinSearch(int val,int sz)
{
    int i;
    int j;
    i=First_OccurWith_BinSearch(val,0,sz-1,sz);
    if(i==-1)
        return i;
    j=Last_OccurWith_BinSearch(val,0,sz-1,sz);

    return j-i+1;
}
int main()
{
    int n;
    cin>>n;
    p=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        p[i]=x;
    }
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" "<<endl;
    }
    int val;
    cin>>val;
    cout<<BinSearch(val,0,n);

    int OccurVal;
    cin>>OccurVal;
    cout<<OccurWith_BinSearch(OccurVal,n);


}
