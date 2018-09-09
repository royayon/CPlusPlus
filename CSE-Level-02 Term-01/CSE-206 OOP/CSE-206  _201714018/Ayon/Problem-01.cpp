#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
namespace myStr{
    int strlen(char* s)
    {
        int i=0,cnt=0;
        while(s[i]!='.')
        {
            if(s[i]!=' ')
            {
                cnt++;
            }
            i++;
        }
        return cnt;
    }
}


int main()
{
    char str[100];


    gets(str);

    int len_my=myStr::strlen(str);
    cout<<"Built in function Output: ";
    cout<<std::strlen(str);
    cout<<"\nOwn function Output: ";
    cout<<len_my+1;


}

