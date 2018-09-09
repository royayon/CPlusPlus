#include<stdio.h>
 int main ()
 {
     int p,k,i,j,n,sum=0;
     printf("eneter n=");
     scanf("%d",&n);
     for(i=1;i<=n;i++)
     {
         p=1;
         for(j=1;j<=i;j++)
             p=p*i;

         if((i%2)==0)

            sum=sum-p;
         else
         sum=sum+p;
     }
     printf("sum= %d", sum);
     return 0;
 }
