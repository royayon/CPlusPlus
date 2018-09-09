#include<stdio.h>
int main()
{
    int n, i ,j ,p , s=0;
    printf("enter n= ");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {

        p=i*i;
        s=s+p;
    }
    printf("%d",s);
    return 0;
}
