#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char *s,*t;
    s = new char[n];
    t = new char[n];
    vector<int> ans;
    int anscnt = 0;

    for(int i = 0; i<n; i++)
    {
        if(s[i] != t[i])
        {
            A:for(int j = i; j<n; j++)
            {
                if(s[j+1] == t[i])
                {
                    swap(s[j] , s[j+1]);
                    ans.push_back(j);
                    anscnt++;
                }
            }
            goto A;
        }
    }
    cout<<anscnt<<endl;
    vector<int>::iterator i;
    for(i=ans.begin(); i!=ans.end(); i++)
        cout<<*i<<" ";

}
