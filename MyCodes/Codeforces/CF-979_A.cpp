#include<iostream>
using namespace std;
string longDivision(string number, int divisor)
{
    // As result can be very large store it in string
    string ans;

    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
       temp = temp * 10 + (number[++idx] - '0');

    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (number.size() > idx)
    {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';

        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }

    // If divisor is greater than number
    if (ans.length() == 0)
        return "0";

    // else return ans
    return ans;
}
int main()
{
    string a;
    cin>>a;
    int len = a.length();
    int m = a.at(len-1) - 48;
    a[len-1] = m+48+1;
    int n = a.at(len-1) - 48;

    if(n%2 == 0)
    {
        cout<<longDivision(a, 2);
    }
    else
    {
        cout<<a;
    }
}
