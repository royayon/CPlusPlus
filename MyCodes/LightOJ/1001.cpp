#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int i=1; i<=T; i++){
        int a;
        cin>>a;
        if(a<=10)
            cout<< 0 << " " << a <<endl;
        else
            cout<< a-10 << " " << 10 <<endl;
    }
}
