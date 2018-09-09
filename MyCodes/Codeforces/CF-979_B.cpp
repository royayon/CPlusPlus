#include<iostream>
#include<cstring>
using namespace std;
int count[100] = {0}, flag = 0;
string visited[100000];
int maxFreq(string string1)
{
    int i, j = 0, k = 0, l, max, index;


    l = string1.length();

    for (i = 0; i < l; i++)
    {
        if (i == 0)
        {
            visited[j++] = string1[i];
            count[j - 1]++;
        }
        else
        {
            for (k = 0; k  < j; k++)
            {
                if (string1.at(i) == visited.at(k))
                {
                    count[k]++;
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                visited[j++] = string1[i];
                count[j - 1]++;
            }
            flag = 0;
        }
    }

    for (i = 0; i < j; i++)
    {
        if ((i == 0) && (visited[i] != ' '))
        {
            max = count[i];
            continue;
        }
        if ((max < count[i]) && (visited[i] != ' '))
        {
            max = count[i];
            index = i;
        }
    }
    return count[index];

}
int main()
{
    int n;
    cin>>n;
    string s1,s2,s3;
    cin>>s1;
    cin>>s2;
    cin>>s3;

    len = s1.length();

    if(len <= n)
    {
        cout<<"Draw";
        return 0;
    }





}
