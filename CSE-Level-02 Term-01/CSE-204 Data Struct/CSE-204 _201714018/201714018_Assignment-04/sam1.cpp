#include<stdio.h>
int main ()
{
    int n,i,j,k,s=0;
    printf("enter n=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    { {  k=1;
        for(j=1;j<=i;j++)
            k=k*j;
    }
    s=s+k;
    }
    printf("%d",s);
    return 0;

}
