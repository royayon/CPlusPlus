#include<stdio.h>
int main()
{
    int i,n,product=1,a;
    scanf("%d",&n);
    for(i=0;i<n;i++)
       // scanf("%d",&a);
    {
        scanf("%d",&a);
        printf("%d",product);
        product=product*a;
        printf("%d*%d=%d\n",product,a,product);
    }
   // printf("%d*%d\n",product,a);
    return 0;
}
