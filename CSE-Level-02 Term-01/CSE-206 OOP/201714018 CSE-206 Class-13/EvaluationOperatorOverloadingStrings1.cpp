#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class String
{
    char *ch;
    int len;
public:
    String(char *_ch="",int _len=0)
    {
        len = _len;
        ch = new char[len];
        for(int i=0; i<len; i++)
        {
            ch[i] = _ch[i];
        }
    }
    bool operator==(String rightObj)
    {
        int flag = 0;
        if(this->len == rightObj.len)
        {
            for(int i=0;i<this->len;i++)
            {
                if(ch[i]==rightObj.ch[i])
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag)
            return 1;
        else
            return 0;
    }

    bool operator!=(String rightObj)
    {
        int flag = 0;
        if(this->len == rightObj.len)
        {
            for(int i=0;i<this->len;i++)
            {
                if(ch[i]==rightObj.ch[i])
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag)
            return false;
        else
            return true;
    }

    void operator=(String rightObj)
    {
        //delete[] ch;
        this->len = rightObj.len;
        ch = new char[len];
        for(int i=0;i<this->len;i++)
        {
            this->ch[i] = rightObj.ch[i];
        }

    }

    String operator-(String rightObj)
    {
        for(int i=0;i<rightObj.len;i++)
        {
            for(int j=0;j<len;j++)
            {
                if(ch[j] == rightObj.ch[i])
                {
                    for(int k=j+1;k<len;k++)
                    {
                        ch[k-1] = ch[k];
                    }
                    j--;
                    len--;
                }
            }
        }
        return *this;
    }

    void operator!()
    {
        for(int i=0;i<len;i++)
        {
            if(ch[i] >= 'a' && ch[i] <= 'z')
            {
                ch[i] = ch[i] - 'a' + 'A';
            }
            else if(ch[i] >= 'A' && ch[i] <= 'Z')
            {
                ch[i] = ch[i] - 'A' + 'a';
            }
        }
    }
    String operator*(int n)
    {
        char* ch1;
        ch1 = new char[len];
        for(int i=0;i<len;i++)
        {
            ch1[i] = ch[i];
        }
        ch = new char[len * n];
        int j=0;
        for(int i=0;i<len*n;i++)
        {
            if(j == len)
            {
                j = 0;
            }
            ch[i] = ch1[j++];

        }
        len = len*n;

        return *this;
    }






    void display()
    {
        for(int i=0; i<len; i++)
        {
            cout<<ch[i];
        }
    }

};


int main()
{
    String s1("Bangladesh",10);
    String s2("glad",4);

    s1=s1-s2;

    s1.display();

    cout<<endl;

    String s4=s1-s2;

    s4.display();

    cout<<endl;

    !s1;
    s1.display();

    cout<<endl;
    String s3=s2*3;
    s3.display();

}

