#include<stdio.h>
int main()
{
    int i,j,k;
     for(i=1;i<=5;i++)
    {
        for(j=1;j<=i;j++)
        if(i==3&&j==2)
            printf(" ");
        else if (i==4&&j==2)
            printf(" ");
             else if (i==4&&j==3)
            printf(" ");
        else
            printf("*");

            printf("\n");
}
return 0;
}
