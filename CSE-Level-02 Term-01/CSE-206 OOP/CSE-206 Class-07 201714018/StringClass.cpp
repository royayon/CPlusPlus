#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class String
{
    char *pt;
    int len;
public:
    String(int ln)
    {
        len=ln;
        pt=new char[len];
    }
    String(const String& st)
    {
        len=st.len;
        pt=new char[st.len];
        for(int i=0;i<st.len;i++)
        {
            pt[i]=st.pt[i];
        }
    }

    char get(int index)
    {
        if(index>=0 && index <len)
            return pt[index];
        else
            return 0;
    }
    int put(int index,char c)
    {
        if(index>=0 && index <len)
            pt[index]=c;
        else
            return -1;
    }
    int getLength()
    {
        return len;
    }
    void print()
    {
        for(int i=0;i<len;i++)
        {
            cout<<pt[i];
        }
    }
    friend String concat(String s1,String s2);
    friend void insertS(String &st, int index, char c);
    ~String()
    {
        delete[] pt;
    }
};
String concat(String s1,String s2)
{
    int ln=s1.len+s2.len;
    String s3(ln);
    for(int i=0;i<ln;i++)
    {
        if(i<s1.len)
            s3.pt[i]=s1.pt[i];
        else
            s3.pt[i]=s2.pt[i-s1.len];
    }
    return s3;
}

void insertS(String &st, int index, char c)
{
    int ln=st.len;
    for(int i=ln;i>=index;i--)
    {
        st.pt[i+1]=st.pt[i];
    }
    st.pt[index]=c;
}


int main()
{
    String s1(4);
    String s2(4);

    s1.put(0,'A');
    s1.put(1,'B');
    s1.put(2,'C');
    s1.put(3,'D');

    s1.print();

    cout<<endl;

    s2.put(0,'1');
    s2.put(1,'2');
    s2.put(2,'3');
    s2.put(3,'4');

    s2.print();


    cout<<endl;


    String s3 = concat(s1,s2);
    s3.print();
    cout<<endl;

    insertS(s3,2,'Z');
    s3.print();

}
