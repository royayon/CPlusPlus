#include<stdio.h>
int main()
{
    int i,n=10,res=0;
    for(i=1;i<n;i++);
    {
        res=res+1;
        if(i!=n){
        printf("%d+",i);
        }
        else
        {
            printf("%d=",i);
        }
        return 0;
    }
}
