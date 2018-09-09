#include<stdio.h>
int main()
{
    int i,n=10,res=0;
    for(i=0;i<=n;i++)
    {
        printf("%d+",res);
        res=res+1;
        printf("%d=%d",i,res);

    }
    return 0;
}
