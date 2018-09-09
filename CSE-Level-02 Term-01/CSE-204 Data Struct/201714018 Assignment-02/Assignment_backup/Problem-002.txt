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
void insertMiddle(int pos,int val,int arraylen)
{
    for(int i=arraylen-1;i>=pos;i--)
    {
        p[i+1]=p[i];
    }
    p[pos]=val;

}
void insert_after_val (int val, int num_of_inputs)
{
    int arraylen=0;
    int*arr=(int*)malloc(num_of_inputs*sizeof(int)); //for insert inputs array
    for(int i=0;p[i]!='\0';i++)
        arraylen++;
    p=(int*)realloc(p,(num_of_inputs+arraylen-1)*sizeof(int)); //resizing the array

    int pos=binSearch(val,0,arraylen-1);
    cout<<"\nInsert: ";
    for(int i=0;i<num_of_inputs;i++)
    {
        cin>>arr[i];
    }
    if(arr[0]>p[pos] && arr[num_of_inputs-1]<p[pos+1])
    {
        int i,j,flag=1;            //checking if the input insertion elements itself are sorted or not!
        for(i=0;i<num_of_inputs;i++)
        {
            for(j=0;j<num_of_inputs-i-1;j++)
            {
                if(p[j]>p[j+1])
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1)
        {
            for(int i=0;i<num_of_inputs;i++)
            {
                insertMiddle(++pos,arr[i],(num_of_inputs+arraylen-1));
            }
            for(int i=0;i<arraylen+num_of_inputs;i++)
            {
                cout<<p[i]<<" ";
            }
        }
        else
        {
            cout<<" \nValue can't be inserted. ";
        }
    }
    else
    {
        cout<<" \nValue can't be inserted. ";
    }



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

    bubbleSort(m);
    cout<<"\nThe Sorted Array is:";
    for(int i=0;i<m;i++)
    {
        cout<<p[i]<<" ";
    }

    p[m]='\0';


    cout<<"\nGive the value to search: ";
    int val;
    cin>>val;
    cout<<"\nGive Num of Inputs: ";
    int num_ins;
    cin>>num_ins;

    insert_after_val(val,num_ins);



}
