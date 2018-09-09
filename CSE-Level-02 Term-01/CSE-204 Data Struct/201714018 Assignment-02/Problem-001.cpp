#include<iostream>
#include<cstdlib>
using namespace std;
int *p;

int initialize(int n)
{
    p=(int*)malloc(n*sizeof(int));
}
/*void deleteMiddle(int pos,int arrsize)
{
    for(int i=pos-1+1;i<=arrsize-1;i++)
    {
        p[i-1]=p[i];
    }
}
void frequency(int n)  //with binary search
{
    int arraysize=0,cnt=0;
    for(int i=0;p[i]!='\0';i++)
    {
        arraysize++;

    }
    int low=0;
    int high=arraysize;
    while (low <= high)
    {
        int m = low + (high-low)/2;
        if (p[m] == n)
        {
            cnt++;
            deleteMiddle(m,arraysize--);
        }

        if (p[m] < n)
            low = m + 1;
        else
            high = m - 1;
    }
    if(cnt==0)
        cout<<"\n"<<n<<" occurs in the array: "<<cnt<<" times.\n";
    else
        cout<<"\n"<<n<<" occurs in the array: "<<cnt+1<<" times.\n";

}*/
void frequency(int n)  //without binary search
{
    int times=0;
    for(int i=0;p[i]!='\0';i++)
    {
        if(p[i]==n)
            times++;

    }

    cout<<"\n"<<n<<" occurs in the array: "<<times<<" times.\n";

}
int main()
{
    cout<<"Give Array Size: ";
    int m;
    cin>>m;
    initialize(m+1);     //this will make an additional space for identification the array size later
    for(int i=0;i<m;i++)
    {
        int val;
        cin>>val;
        p[i]=val;
    }
    cout<<"\nThe Array is:";
    for(int i=0;i<m;i++)
    {
        cout<<p[i]<<" ";
    }

    cout<<"\nGive Input n for frequency: ";
    int n;
    cin>>n;
    p[m]='\0';


    frequency(n);




}
