#include<iostream>
#define MAX 10
#define true 1
#define false 0
using namespace std;
class Stack{
int top;
int *p;
public:
Stack(){
top=-1;
p=new int[MAX];
}
void push(int x){
if(top==MAX-1){
    cout<<"stack full";
    return;
}
else{
    top++;
    p[top]=x;
}

}
int pop(){
    int temp;
if(top==-1){
    cout<<"stack empty";
}

    temp=p[top];
    top--;
    return temp;

}

void display(int s){
for(int i=0;i<s;i++){
    cout<<p[i];
}
}


};
int main(){
    int ele,coun=0;
int size1;
int size2;
int po;
Stack s1,s2;
cout<<"enter size of stack:"<<endl;
cin>>size1;
cout<<"enter elements of stack:"<<endl;
for(int i=0;i<size1;i++){
cin>>ele;
s1.push(ele);
}
for(int i=0;i<size1;i++){
    po=s1.pop();
    s2.push(po);
}
cout<<"perform dequeue how many times:";
cin>>size2;
for(int i=0;i<size2;i++){
    s2.pop();
    coun++;
}
size1=size1-coun;
s2.display(size1);
}
