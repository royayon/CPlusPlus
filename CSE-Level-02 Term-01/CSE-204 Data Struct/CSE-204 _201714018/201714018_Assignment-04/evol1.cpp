#include<stdio.h>
int main()
{
    int i, j, k, n;
    for(i=1;i<=7;i++)
    {
        for(j=1;j<=i;j++)
            printf("%d", j);
            for(k=6;k>=i;k--)
        printf("*");
    printf("\n");
    }
    return 0;

}
