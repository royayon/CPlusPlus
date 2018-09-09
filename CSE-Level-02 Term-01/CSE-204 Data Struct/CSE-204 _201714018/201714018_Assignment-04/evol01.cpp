#include<stdio.h>
int main()
{
    float i,j,s=0;
    int n;
    printf("enter n=");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
{
    if((int)i%2==0)
        s=s-(i/(i+1));
        else
            s=s+(i/(i+1));
}

printf("%f", s);
return 0;
}
