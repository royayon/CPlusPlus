#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class String
{
    char *ch;
    int len;
public:
    String(char *_ch , int _len)
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
        delete[] ch;
        this->len = rightObj.len;
        ch = new char[len];
        for(int i=0;i<this->len;i++)
        {
            this->ch[i] = rightObj.ch[i];
        }
    }

    void operator~()
    {
        for(int i=0; i<=(len-1)/2; i++)
        {
            swap(ch[len-1-i] , ch[i]);
        }
    }

    void operator+=(String rightObj)
    {
        int newLen = this->len + rightObj.len;
        this->ch = (char*)realloc(this->ch,newLen);
        for(int i=0; i<=(this->len + rightObj.len)-1 ; i++)
        {
            if(i > this->len-1)
            {
                ch[i] = rightObj.ch[abs(this->len-i)];
            }
        }
        this->len = this->len + rightObj.len;
    }
    void operator<<(int n)
    {
        char *newch = new char[this->len];
        int j = 0;
        for(int i=n; i<len; i++)
        {
            newch[j++] = ch[i];
        }
        for(int i=0; i<n; i++)
        {
            newch[j++] = ch[i];
        }
        ch = newch;
    }

    void operator>>(int n)
    {
        char *newch = new char[this->len];
        int j = n;
        for(int i=0; i<len-n; i++)
        {
            newch[j++] = ch[i];
        }
        j=0;
        for(int i=len-n; i<len; i++)
        {
            newch[j++] = ch[i];
        }
        ch = newch;
    }

    void operator()(int leftindex , int rightindex)
    {
        for(int i=leftindex-1;i<rightindex;i++)
        {
            cout<<ch[i];
        }
    }
    void operator()(char c)
    {
        for(int i=0;i<len;i++)
        {
            if(ch[i] == c)
                cout<<i<<" ";
        }
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
    String s1("abcd",4);
    String s2("def1e2e",7);

    cout<<(s1==s2);
    cout<<endl;
    cout<<(s1!=s2);

    cout<<endl;

    ~s1;
    s1.display();
    ~s1;


    cout<<endl;

    ~s2;
    s2.display();
    ~s2;

    cout<<endl;
    s1+=s2;
    s1.display();

    cout<<endl;
    s2<<2;
    s2.display();

    cout<<endl;
    s2>>2;
    s2.display();

    cout<<endl;
    s1=s2;
    s1.display();

    cout<<endl;
    s2(2,4);

    cout<<endl;
    s2('e');


}
