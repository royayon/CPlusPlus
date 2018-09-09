#include<iostream>
using namespace std;
int main()
{
    int arr[14],arrc[14],maxArr=0,maxi=0;
    for(int i=0;i<14;i++)
    {
        cin>>arr[i];
        //maxArr = max(maxArr,arr[i]);
    }
    int maxcnt=0;
    for(int k=0;k<14;k++)
    {
        for(int i=0;i<14;i++)
        {
            arrc[i]=arr[i];
        }
        maxArr= arr[k];
        /*for(int i=0;i<14;i++)
        {
            if(arr[i]==maxArr)
                maxi=i;
        }*/
        maxi=k;
        int index=maxi+1;
        arr[maxi]=0;
        while(maxArr--)
        {
            if(index==14)
                index=0;
            arr[index++]++;

        }
        /*for(int i=0;i<14;i++)
        {
            cout<<arr[i];
        }*/
        int cnt=0;

        for(int i=0;i<14;i++)
        {
            if(arr[i]%2==0)
            {
                cnt+=arr[i];
            }
        }
        maxcnt=max(maxcnt,cnt);
        for(int i=0;i<14;i++)
        {
            arr[i]=arrc[i];
        }
    }

    cout<<maxcnt;

}
