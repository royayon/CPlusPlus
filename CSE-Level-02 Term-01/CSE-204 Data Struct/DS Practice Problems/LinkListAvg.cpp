#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class List
{
    struct node *head;
    struct node *tail;
public:
    List()
    {
        head=NULL;
        tail=NULL;
    }
    void createList(int x)
    {
        node *newNode=new node;
        newNode->data=x;
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
    }
    void displayList()
    {
        node *prev=new node;
        prev=head;
        if(head==NULL)
        {
            cout<<"List is Empty!!"<<endl;
            return;
        }
        while(prev != NULL)
        {
            cout<<prev->data<<" ";
            prev=prev->next;
        }
    }
    void twoListAvg(List l2)
    {
        node *prev1=new node;
        prev1=this->head;

        node *prev2=new node;
        prev2=l2.head;
        while(prev1!=NULL)
        {
            cout<< (prev1->data + prev2->data)/2 <<" ";
            prev1 = prev1->next;
            prev2 = prev2->next;
        }
    }

};

int main()
{
    List l1;
    l1.createList(10);
    l1.createList(20);
    l1.createList(30);
    l1.createList(40);
    l1.createList(50);
    l1.createList(60);

    cout<<"L1==>>   ";
    l1.displayList();

    cout<<endl;

    List l2;
    l2.createList(20);
    l2.createList(30);
    l2.createList(40);
    l2.createList(50);
    l2.createList(60);
    l2.createList(70);

    cout<<"L2==>>   ";
    l2.displayList();

    cout<<endl;

    cout<<"AvgL1~l2:";
    l1.twoListAvg(l2);
}
