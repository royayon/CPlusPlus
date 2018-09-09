#include<iostream>
#include<cstdlib>
using namespace std;
int *p;

int initialize(int n)
{
    p=(int*)malloc(n*sizeof(int));
}

void frequency(int n)
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
