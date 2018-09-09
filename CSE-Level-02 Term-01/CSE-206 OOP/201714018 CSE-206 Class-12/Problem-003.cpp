#include<iostream>
#include<cstring>

using namespace std;

class String
{
    int len;
    char * str;
public:
    String(char *_str)
    {
        str = _str;
        len = strlen(_str);
    }
    String(const String& obj)
    {
        len = obj.len;
        str = new char[len];
        for(int i=0;i<len;i++)
        {
            str[i] = obj.str[i];
        }

    }
    void display()
    {
        cout<<str<<endl;
    }

    String operator+ (String right)
    {
        int l = len+right.len;
        char *n = new char[l];
        int k =0;

        for(int i=0; i<l; i++)
        {
            if(i<len)
                n[i] = str[i];
            else
            {
                n[i] = right.str[k];
                k++;
            }
        }
        String ret(n);
        return ret;
    }

    bool operator==(String right)
    {
        if(this->str == right.str)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator!=(String right)
    {
        if(this->str != right.str)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ~String()
    {
        delete str;
    }

};

int main()
{
    String s1("hello ");
    String s2("world");

    s1.display();
    s2.display();

    String s3 = s1+s2;
    s3.display();

    int i = s1!=s2;
    int j = s1==s2;

    cout<<i<<endl;
    cout<<j<<endl;
}
