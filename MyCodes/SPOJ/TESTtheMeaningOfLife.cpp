#include<iostream>
using namespace std;
int main()
{
    int inp,flag=1;
    do
    {
        cin>>inp;
        if(inp==42)
        {
            flag=0;
            continue;
        }
        if(flag)
            cout<<inp<<endl;
    }while(flag);
}
