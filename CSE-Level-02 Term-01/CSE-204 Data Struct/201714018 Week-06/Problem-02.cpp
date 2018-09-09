#include<iostream>
using namespace std;

struct node
{
    int value;
    struct node *next;
};

class CList
{
    struct node *last;
public:
    CList()
    {
        last=NULL;
    }
    void insertList(int x)
    {
        if(last==NULL)
        {
            node*newItm=new node;
            newItm->value=x;
            newItm->next=NULL;

            last=newItm;
            last->next=last;
        }
        else
        {
            node*newItm=new node;
            newItm->value=x;
            newItm->next=NULL;

            newItm->next=last->next;
            last->next=newItm;
            last=newItm;

        }
    }
    void createList(int n)
    {
        for(int i=1;i<=n;i++)
        {
            insertList(i);
        }
    }
    void survivor(int n)
    {
        node *prev1=new node;
        node *prev2=new node;

        prev2=last->next->next;
        prev1=last->next;

        int cnt=n-1;
        while(cnt)
        {
            int dead=prev2->value;
            prev1->next=prev2->next;

            prev1=prev1->next;
            prev2=prev2->next->next;

            cout<<dead<<" ";
            cnt--;
        }
        cout<<"Survivor is: "<<prev1->value<<endl;

    }
};

int main()
{
    CList cl1;
    int n;
    cin>>n;
    cl1.createList(n);
    cl1.survivor(n);

}
