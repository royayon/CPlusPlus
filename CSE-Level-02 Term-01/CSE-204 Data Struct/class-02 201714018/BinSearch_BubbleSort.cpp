#include<iostream>
#include<cstdlib>
using namespace std;
int *p;

int initialize(int n)
{
    p=(int*)malloc(n*sizeof(int));
}
void bubbleSort(int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j]>p[j+1])
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
int binSearch(int val,int low,int high)
{
    while (low <= high)
    {
        int m = low + (high-low)/2;
        if (p[m] == val)
            return m;
        if (p[m] < val)
            low = m + 1;
        else
            high = m - 1;
    }
    return -1;
}

int main()
{
    cout<<"Enter Array Size:";
    int n;
    cin>>n;
    initialize(n);
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        p[i]=val;
    }
     cout<<"The Array is:";
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }


    bubbleSort(n);

    cout<<"\nThe Sorted Array is:";
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }

    cout<<"\nEnter an Element to Search:";
    int a;
    cin>>a;
    int v=binSearch(a,0,n-1);
    if(v!=-1)
    {
        cout<<"Found!"<<v;
    }
    else
    {
        cout<<"Not Found!";
    }

    return 0;
}
