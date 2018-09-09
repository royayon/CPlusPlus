#include<iostream>
using namespace std;

class comPlx{
    int real;
    int img;
    friend void add();
    friend void sub();
public:
    void setter(int r,int i)
    {
        real=r;
        img=i;
    }
};
void add()
{
    comPlx c1,c2;
    int r1,i1,r2,i2;
    cout<<"\nInput First Complex Num: ";
    cin>>r1>>i1;
    c1.setter(r1,i1);
    cout<<"\nInput Second Complex Num: ";
    cin>>r2>>i2;
    c2.setter(r2,i2);

    int sumReal=c1.real+c2.real;
    int sumImg=c1.img+c2.img;

    cout<<"\nThe sum is: "<<sumReal<<"+i"<<sumImg;

}

void sub()
{
    comPlx c1,c2;
    int r1,i1,r2,i2;
    cout<<"\nInput First Complex Num: ";
    cin>>r1>>i1;
    c1.setter(r1,i1);
    cout<<"\nInput Second Complex Num: ";
    cin>>r2>>i2;
    c2.setter(r2,i2);

    int subReal=c1.real-c2.real;
    int subImg=c1.img-c2.img;

    cout<<"\nThe sub is: "<<subReal<<"+i"<<subImg;

}
int main()
{
    add();
    sub();
}
